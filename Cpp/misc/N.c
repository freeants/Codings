/*
    File:       N.c - Output the highest/lowest digits of an integer from input.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */

extern int printf(const char *format, ...);
char hibit, lobit;

int getStrLen(char s[])
{
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    return cnt;
}

void insertionSort(char arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
    hibit = arr[length - 1];
    lobit = arr[0];
}

int main(int argc, char **argv)
{
    /** Check cmd line args */
    if (argc != 2)
    {
        printf("Usage: N n\t//n is the integer to be phased\n");
        return 1;
    }

    /** Get it sorted */
    insertionSort(argv[1], getStrLen(argv[1]));

    /** Output to stdout */
    printf("%c,%c\n", hibit, lobit);

    return 0;
}