// Example program
#include <stdio.h>
#include<math.h>

int firstDigit(int number);
int lastDigit(int number);
void swapFirstLast(int number);
int sumOfDigits(int number);
int reverseNumber(int number);

int main()
{
  printf("%d\n", firstDigit(7689));
  printf("%d\n", firstDigit(5678));
  swapFirstLast(345678);
  printf("%d\n", sumOfDigits(456789));
  printf("%d\n", reverseNumber(456789));
}

int firstDigit(int number)
{
    while(number > 10)
    {
        number /=10;
    }
    return number%10;
}

int lastDigit(int number)
{
    return number%10;
}

void swapFirstLast(int number)
{
    int swappedNumber = 0;
    int lastDigit  = number % 10;
    int digitsNumber = (int)log10(number); 
    int firstDigit = (int)(number / pow(10, digitsNumber)); 
    swappedNumber  = lastDigit;
    swappedNumber *= (int) pow(10, digitsNumber);
    swappedNumber += number % ((int) pow(10, digitsNumber));
    swappedNumber -= lastDigit;
    swappedNumber += firstDigit;
    printf("%d\n",swappedNumber);
}

int sumOfDigits(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number%10;
        number/=10;
    }
    return sum;
}

int reverseNumber(int number)
{
    int reversedNumber = 0;
    int digit = 0;
    while(number > 0)
    {
        digit = number%10;
        reversedNumber = reversedNumber*10 + digit;
        number/=10;
    }
    return reversedNumber; 
}
