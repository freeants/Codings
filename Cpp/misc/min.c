/*
    min.c - output the minimal integer from three inputs, avoid using built-in 
            libs as much as possiable.
    Author: freeants, All rights reserved.
*/
extern int printf(const char *format, ...);
extern int scanf(const char *format, ...);

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    int a, b, c;
    printf("Input three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The minial of the three: %d\n", MIN(MIN(a, b), c));

    return 0;
}
