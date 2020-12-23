#include <iostream>
#include <string>
#include <fstream> // File operations
#include <random>  // Generate random numbers
using namespace std;

char *FILENAME;
int n;       // Number of integers in total
string *arr; // String arr holding all numbers

bool needSwap(string a, string b)
{
    if (a + b <= b + a)
        return false;
    return true;
}

//void GetInput()
//{
//    cout << "How many numbers in total? (n): ";
//    cin >> n;
//}

int GenRandomNumber()
{
    random_device rd;                           //obtain a random number from hardware
    mt19937 gen(rd());                          //seed the generator
    uniform_int_distribution<> distr(1, 32768); //define the range

    //return the rand value
    return distr(gen);
}

void BuildDataArray()
{
    cout << "Building data array with random integers ... (size: " << n << ")" << endl;
    arr = new string[n];

    // Assign values to array
    for (int i = 0; i < n; i++)
        arr[i] = to_string(GenRandomNumber()); //this forms randomly filled numbers
}

void PrintArray(string *a)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void SaveFile()
{
    ofstream ofs(FILENAME);
    ofs.precision(n + 1);
    for (int i = 0; i < n; i++)
        ofs << arr[i];
    ofs << endl;
}

void test()
{
    string tmp;
    // Print the original number
    cout << "The original numbers: " << endl;
    PrintArray(arr);
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (needSwap(arr[j - 1], arr[j]))
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    //Print the mixed numbers
    cout << "   The mixed numbers: " << endl;
    PrintArray(arr);
    cout << endl;

    // Save file if FILENAME exists, otherwise skip file save.
    if (FILENAME != NULL)
    {
        SaveFile();
        cout << "File " << FILENAME << " saved." << endl;
    }
}

int main(int argc, char **argv)
{
    // Check cmd line args
    if (argc <= 1 || argc > 3)
    {
        cerr << "Usage: JoinNum n FILENAME" << endl;
        return 1;
    }

    n = stoi(argv[1]);
    FILENAME = argv[2];

    try
    {
        // Get input of n
        // GetInput();
        // Build data array
        BuildDataArray();
        // Do task
        test();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    delete[] arr;
    return 0;
}