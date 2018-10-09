#include <stdio.h>

void binaryToOctal(long int number);

int main()
{
  printf("Number:%lo",001111010);
  binaryToOctal(001111010);
  return 0;
}

void binaryToOctal(long int number)
{
    long int octal = 0, j = 1, remainder;
    while(number != 0)
    {
        remainder = number % 10;
        octal +=(remainder * j);
        j*=2;
        number/=10;
        printf("Remainder:%lo, number:%lo, j:%lo, octal:%lo\n", remainder,number,j,octal);
    }
    printf("Octal: %lo\n", octal);
}
