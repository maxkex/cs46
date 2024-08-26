#include <stdio.h>

int main()
{
    //define numerators and denominators
    int num1, denom1, num2, denom2, num3, denom3;
    printf("This program will sum two fractions.\n");

    //ask user for fractions
    printf("Enter the first fraction: ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter the second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    //calculation and printing
    num3 = (num1 * denom2) + (num2 * denom1);
    denom3 = denom1 * denom2;
    printf("The sum is %d/%d. \n", num3, denom3);

    return 0;
}