/**
 * GuessRandomBinAuto.cc
 * (c), freeansts. All rights reserved.
 **/

#include <iostream>
#include <random>
using namespace std;

#define MAXATTEMPTS 7
#define MAX 999999999
#define MIN 0

int *arr;     // The array that holds all ranges from [MIN, MAX]
int Guess;    // Guessed number
int Attempt;  // Guess attempts
int MagicNum; // The random "magic number"

/*
 * GenMagicNum() - Generate magice number randomly.
 */
void GenMagicNum()
{
    random_device rd;                           //obtain a random number from hardware
    mt19937 gen(rd());                          //seed the generator
    uniform_int_distribution<> distr(MIN, MAX); //define the range

    //assign the rand value to magic number
    MagicNum = distr(gen);
}

/*
 * BinSearch() - Binary search to locate the magic number.
 * parameters:
 * *range - array that holds the (splited) total numbers
 *  int n - array size
 *  int key - the magic number
 * return:
 *  mid, index of the array
 *  -1, no search found
 */
int BinSearch(int *range, int n, int key)
{
    int mid, front = 0, back = n - 1;
    Attempt = 0;

    while (front <= back)
    {
        Attempt++;
        mid = (front + back) / 2;
        cout << "#" << Attempt << " Range: [" << front << ", " << back << "]"
             << " --> Guessed: " << range[mid] << endl;

        if (range[mid] == key)
            return mid;

        if (range[mid] < key)
            front = mid + 1;
        else
            back = mid - 1;
    }
    return -1;
}

int main()
{
    // Start Guess game
    cout << "Binary search a random number between " << MIN << " and " << MAX << endl
         << "Display attemps and medium results." << endl;

    // Generate the magic number
    GenMagicNum();

    // Define the array that holds
    arr = new int[MAX];

    // Assign values to array
    for (int i = 0; i < MAX; i++)
        arr[i] = i;

    // Start Binary search
    int index = BinSearch(arr, MAX, MagicNum);
    if (index)
    {
        cout << "Guesses found, used " << Attempt << " times" << endl;
        cout << "Magic number: " << MagicNum << " Guessed number: " << arr[index] << endl;
    }
    else
    {
        cout << "Guess failed." << endl;
    }

    return 0;
}
