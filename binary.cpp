#include <iostream>

void setbit(unsigned int &number, unsigned int bitnumber);
int getbit(unsigned int number, unsigned int bitnumber);
void printbinary(unsigned int number);

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

