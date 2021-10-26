/*
    File    :   rss.cc 
    Purpose :   Read 1M float numbers from file M1, sort numbers and save file, all 3 steps 
                need to complete around 10 seconds on normal PC.
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1 Mar 27, 2021. 
*/

#include <chrono>    // for timing
#include <fstream>   // File operations
#include <random>    // Generate random numbers
#include <algorithm> // std::sort
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_SIZE 1000000  // Size of data dictionary
#define SRC_FILE "M1.txt" // Source file name
#define DST_FILE "M2.txt" // Destination file name

float *a; // Data dictionary

/*
 * Lamda expression for displaying stats.
 */
static auto dispResult = [](string str, auto diffTime)
{
    cout << left << setw(30) << str << setw(20) << chrono::duration_cast<chrono::microseconds>(diffTime).count() << endl;
};

void FileRead(string file_name)
{
    ifstream ifs(file_name);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ifs >> a[i];
    }
}

void FileSave(string file_name)
{
    ofstream ofs(file_name);
    for (int i = 0; i < MAX_SIZE; i++)
        ofs << a[i] << endl;
    ofs.close();
}

/*
 * Build data dictionary and count timing.
 */
void BuildDataDictionary()
{
    // Define the array that holds all data
    a = new float[MAX_SIZE];

    random_device rd;                                 //obtain a random number from hardware
    mt19937 gen(rd());                                //seed the generator
    uniform_real_distribution<> distr(0.0, MAX_SIZE); //define the range
    // Assign values to array
    for (int i = 0; i < MAX_SIZE; i++)
        a[i] = distr(gen); //this forms randomly filled numbers
}

void doTests()
{
    cout << "/////////////////////////////////////////////////////////////////" << endl;
    cout << left << setw(30) << "Operations" << setw(20) << "Time elapsed(μ)" << endl;

    /* 0. Generate 1M random numbers& save to file*/
    auto t = chrono::high_resolution_clock::now(); //get start time
    BuildDataDictionary();
    FileSave("M1.txt");
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    dispResult("0. Build data & save file", t0 - t);

    /* 1. Read from source file */
    FileRead(SRC_FILE);
    auto t1 = chrono::high_resolution_clock::now(); //get start time
    dispResult("1. File reads", t1 - t0);

    /* 2. Sorting the numbers */
    sort(a, a + MAX_SIZE);
    auto t2 = chrono::high_resolution_clock::now(); //get start time
    dispResult("2. Sorting", t2 - t1);

    /* 3. Save the sorted numbers to destination file */
    FileSave(DST_FILE);
    auto t3 = chrono::high_resolution_clock::now(); //get start time
    dispResult("3. File save", t3 - t2);

    /* Print overview */
    //dispResult("Total time elapsed", t3 - t0);
    auto timeElapsed = chrono::duration_cast<chrono::microseconds>(t3 - t).count();
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "/////////////////////////////////////////////////////////////////" << endl;
    cout << left << setw(30) << " Total time" << setw(20) << timeElapsed << (double)timeElapsed / 1000000 << " seconds"
         << endl;
    cout << left << setw(30) << " Completed @ " << setw(20) << ctime(&timenow) << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Read, Sort and Save 1M floating numbers (C++) ..." << endl;
    try
    {
        /* Start the tests */
        doTests();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    delete[] a; // release memory
    return 0;
}