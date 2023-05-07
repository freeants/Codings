/*
    File:       inch-cm.c - Print the inch-cm convertion table as per choices.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */

#include <stdio.h>
#define INCH_CM_RATIO 2.54

const char *menu_text = "Conversion table between inches and centimeters\n(1) inches to centimeters\n(2) centimeters to inches\n\nChoose conversion type (1,2): ";
int choice, starting, ending;

/*
 * void menu() - print menu for choices
 */
void menu()
{
    /* prompt for menu choice */
    printf("%s", menu_text);
    scanf("%d", &choice);

    /* prompt for range choices */
    printf("\nEnter starting value: ");
    scanf("%d", &starting);
    printf("\nEnter ending value: ");
    scanf("%d", &ending);
}

void inches_cm()
{
    /* print table head */
    printf("\nInches\tcm\n");

    for (int steps = starting; steps <= ending; steps += 4)
    {
        printf("%d\t%.1f\n", steps, (double)steps * INCH_CM_RATIO);
    }
}

void cm_inches()
{
    /* print table head */
    printf("\ncm\tInches\n");

    for (int steps = starting; steps <= ending; steps += 10)
    {
        printf("%d\t%.1f\n", steps, (double)steps / INCH_CM_RATIO);
    }
}

int main()
{

    /* show menu first */
    menu();

    /* do convertions according to choice */
    switch (choice)
    {
    case 1:
        /* inches_cm() is called */
        inches_cm();
        break;
    case 2:
        /* inches_cm() is called */
        cm_inches();
        break;
    default:
        /* do menu again */
        break;
    }

    return 0;
}
