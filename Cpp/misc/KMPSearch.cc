// C++ program for implementation of KMP pattern searching
// algorithm
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100000000 // Size of data dictionary

char txt[MAX_SIZE]; // array for all data
char *SRC_FILE;     // Filename to be searched
char *Pat;          // Pattern to search for

void FileRead(string file_name)
{
    ifstream ifs(file_name);
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        ifs >> txt[i];
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
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
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

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
            printf("Found pattern at index %d \n", i - j - 1);
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

/* Driver program to test above function
int main()
{
    // char txt[] = "ABABDABACDABABCABAB";
    // char pat[] = "ABABCABAB";
    // printf("Enter birth date (YYYYMMDD): ");
    // scanf("%s", &pat);
    FileRead(SRC_FILE);
    KMPSearch(pat, txt);
    // delete[] txt, pat;
    return 0;
} */

int main(int argc, char **argv)
{
    // Check cmd line args
    if (argc != 3)
    {
        cerr << "Usuage: KMPSearch Pattern FILE\n";
        return 1;
    }
    Pat = argv[1];
    SRC_FILE = argv[2];

    try
    {
        FileRead(SRC_FILE);
        KMPSearch(Pat, txt);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
