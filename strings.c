#include <stdio.h>

int strLength(char str[]);
void printLength(char str[]);
void copyString(char src[], char dst[]);
void printString(char str[]);
void concatenateString(char str[], char str2[], char str3[]);
int compareStrings(char *str, char *str2);

int main()
{
    char str[] = "Body and brain";
    char str2[] = "My old friend";
    printLength(str);
    printLength(str2);
    char str3[20];
    copyString(str2,str3);
    printString(str3);
    char str4[30];
    concatenateString(str, str2, str4);
    printString(str4);
    printf("d\n",compareStrings("My mum.", "My mummy."));
    printf("d\n",compareStrings("My mum.", "My mum."));
    return 0;
}

int strLength(char str[])
{
    int length = 0;
    while(str[length] != 0)
    {
        length++;
    }
    return length;
}

void printLength(char str[])
{
    printf("Length of '%s' is %d.\n", str, strLength(str));
}

void copyString(char src[], char dst[])
{
    for(int i = 0; src[i] != '\0'; i++)
    {
        dst[i] = src[i];
    }
}
void printString(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void concatenateString(char str[], char str2[], char str3[])
{
    int length_str = strLength(str);
    int length_str2 = strLength(str2);
    int length_str3 = length_str2 + length_str;
    for(int i = 0; i < length_str; i++)
    {
        str3[i] = str[i];
    }
    for(int i = length_str; i < length_str3; i++)
    {
        str3[i] = str2[i - length_str];
    }
}

int compareStrings(char *str, char *str2)
{
    int i = 0;
    while(str[i] == str2[i]&& strLength(str) == strLength(str2))
    {
        i++;
    }
    return (str[i] - str2[i]);
}
