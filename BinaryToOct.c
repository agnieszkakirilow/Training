#include <stdio.h>

void binaryToOctal(long int number);
void binaryToDecimal(long int number);

int main()
{
  printf("Number:%lo",001111010/10);
  binaryToOctal(001111010);
  binaryToDecimal(001111010);
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

void binaryToDecimal(long int number)
{
    long int decimal = 0;
    int base = 1, remainder;
    while (number > 0)
    {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10 ;
        base *= 2;
    }
    printf("decimal:%d\n", decimal);
}
