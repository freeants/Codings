/*
   KMPSearch.cc
   C++ program for implementation of KMP pattern searching algorithm.
   clang++ -o KMPSearch KMPSearch.cc -std=c++17 -O3
   Author: ffu@alumni.sjtu.edu.cn
   "No License, No nonsense"
*/

#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

#define MAX_SIZE 150000000 // Size of data dictionary

char txt[MAX_SIZE]; // array for all data
string FILENAME;    // Filename to be searched
string Pattern;     // Pattern to search for

// structure to set thousands separator
struct space_out : std::numpunct<char>
{
    char do_thousands_sep() const { return ','; }    // separate with ','
    std::string do_grouping() const { return "\3"; } // group of 3 digits
};

void FileRead(string file_name)
{
    ifstream ifs(file_name);
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        ifs >> txt[i];
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, size_t M, size_t *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    size_t i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt)
{
    size_t M = pat.size();
    size_t N = txt.size();

    size_t lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            // printf("Pattern found @ %d \n", i - j - 1);
            cout << "Pattern found @ " << i - j - 1 << "\n";
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main(int argc, char **argv)
{
    // Check cmd line args
    if (argc != 3)
    {
        cerr << "syntax:\n KMPSearch Pattern_String FILE_NAME" << '\n';
        return 1;
    }
    Pattern = argv[1];
    FILENAME = argv[2];
    
    // set thousand separator
    std::cout.imbue(std::locale(std::cout.getloc(), new space_out)); 

    try
    {
        FileRead(FILENAME);
        KMPSearch(Pattern, txt);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}