#include <iostream>

void setbit(unsigned int &number, unsigned int bitnumber);
int getbit(unsigned int number, unsigned int bitnumber);
void printbinary(unsigned int number);
void clearbit(unsigned int &number, unsigned int bitnumber);
void togglebit(unsigned int &number, unsigned int bitnumber);
int highestsetbit(unsigned int number);
int lowestsetbit(unsigned int number);

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
