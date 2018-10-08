#include <iostream>

void setbit(unsigned int &number, unsigned int bitnumber);
int getbit(unsigned int number, unsigned int bitnumber);
void printbinary(unsigned int number);
void clearbit(unsigned int &number, unsigned int bitnumber);
void togglebit(unsigned int &number, unsigned int bitnumber);
int highestsetbit(unsigned int number);
int lowestsetbit(unsigned int number);
int leastsignificantbit(unsigned int number);
int mostsignificantbit(unsigned int number);
int counttrailingzeroes(unsigned int number);
int countleadingzeroes(unsigned int number);
void flipbits(unsigned int &number);
void countzeroesandones(unsigned int number);
int rotatenumberleft(int number, int rotations);
int rotatenumberright(int number, int rotations);
void swap(int &a, int &b);
int isuneven(int num);

int main()
{
  unsigned int number = 0;
  for(int i = 31; i >=0; i = i-2)
  {
      setbit(number,i);
  } 
  for(int i = 31; i >=0; i--)
  {
      std::cout << getbit(number, i);
  }
  std::cout << std::endl;
  unsigned int mynumber = 17;
  printbinary(mynumber);
  std::cout << std::endl;
  clearbit(mynumber,4);
  printbinary(mynumber);
  std::cout << std::endl;
  togglebit(mynumber,4);
  printbinary(mynumber);
  std::cout << std::endl;
  highestsetbit(15);
  lowestsetbit(0);
  std::cout << leastsignificantbit(13) << std::endl;
  std::cout << mostsignificantbit(13) << std::endl;
  std::cout << counttrailingzeroes(0) << std::endl;
  std::cout << countleadingzeroes(22) << std::endl;
  std::cout << mynumber << std::endl;
  flipbits(mynumber);
  std::cout << mynumber << std::endl;
  countzeroesandones(16);
  std::cout << rotatenumberleft(-15,2) << std::endl;
  std::cout << rotatenumberright(-15,2) << std::endl;
  int a = -5,b = 17;
  swap(a,b);
  std::cout << a << "   " << b << "\n";
  std::cout << isuneven(-6) << std::endl;
}

void setbit(unsigned int &number, unsigned int bitnumber)
{
    number |= ( 1 << bitnumber );
}

int getbit(unsigned int number, unsigned int bitnumber)
{
    return (number >> bitnumber) & 1;
}

void printbinary(unsigned int number)
{
    for(int i = 31; i >=0; i--)
  {
      std::cout << ((number >> i) & 1);
  }
}

void clearbit(unsigned int &number, unsigned int bitnumber)
{
    number &= ~( 1 << bitnumber);
}

void togglebit(unsigned int &number, unsigned int bitnumber)
{
    number ^= ( 1 << bitnumber );
}

int highestsetbit(unsigned int number)
{
    int bitset = -1;
    for(int i = 31; i >=0; i--)
    {
        if((number >> i) & 1)
        {
            bitset = i;
            break;
        }
    }
    bitset == -1 ? std::cout << "No bit is set\n": std::cout << bitset << " bit is the highest bit set\n";
    return bitset;
}

int lowestsetbit(unsigned int number)
{
    int bitset = -1;
    for(int i = 0; i < 32; i++)
    {
        if((number >> i) & 1)
        {
            bitset = i;
            break;
        }
    }
    bitset == -1 ? std::cout << "No bit is set\n": std::cout << bitset << " bit is the lowest bit set\n";
    return bitset;
    
}

int leastsignificantbit(unsigned int number)
{
    return (number&1);
}
int mostsignificantbit(unsigned int number)
{
    return 1;
}

int counttrailingzeroes(unsigned int number)
{
    int count = 0;
    if(number == 0)
    {
        return 0;
    }
    while(~(number >> count) & 1)
    {
            count++;
    }
    return count;
}

int countleadingzeroes(unsigned int number)
{
    int count = 32;
    if(number == 0)
    {
        return 32;
    }
    while(~(number >> count) & 1)
    {
            count--;
    }
    return 31 - count;
}

void flipbits(unsigned int &number)
{
    number = ~number;   
}

void countzeroesandones(unsigned int number)
{
    int countones = 0;
    int countzeroes = 0;
    for(int i = 0; i < 32; i++)
    {
        if((number >> i) & 1)
        {
            countones++;
        }
        else
        {
            countzeroes++;
        }
    }
    std::cout << "zeroes:" << countzeroes << " ones:" << countones << std::endl;
}

int rotatenumberleft(int number, int rotations)
{
    int droppedbit = (number >> 31)&1;
    while(rotations--)
    {
        number = (number << 1)|droppedbit;
    }
    return number;
}

int rotatenumberright(int number, int rotations)
{
    int droppedbit = number&1;
    while(rotations--)
    {
        number = (number >> 1);
        std::cout << number << " - NUMBER\n";
        number |= (droppedbit << 31);
        std::cout << number << " - NUMBER\n";
    }
    return number;
}

void swap(int &a, int &b)
{
    a ^=b;
    b ^=a;
    a ^=b;
}

int isuneven(int num)
{
    return (num&1);
}