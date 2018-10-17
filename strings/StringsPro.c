#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "StringsPro.h"


void printString(char str[])
{
   for(int i = 0; str[i] != '\0'; i++)
   {
       printf("%c", str[i]);
   }
   printf("\n");
}

void lowerToUpper(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
    }
}

void toggleString(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] +=32;
        }
    }
}

void countSigns(char str[])
{
    int alphabets = 0, digits = 0, other = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( (str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) )
        {
            alphabets++;
        }
        else if ((str[i] >= 32 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 123 && str[i] <= 126))
        {
            other++;
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            digits++;
        }
    }
    printf("Alphabets: %d, Other: %d, Digits: %d\n", alphabets, other, digits);
}

void countVovels(char str[])
{
    int vovel = 0, consonant = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( (str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) )
        {
            if( str[i] == 'a' || str[i] == 'A' || str[i] == 'e'|| str[i] == 'E'|| str[i] == 'i'|| str[i] == 'I'|| str[i] == 'o'|| str[i] == 'O'|| str[i] == 'u'|| str[i] == 'U')
            {
                vovel++;
            }
            else
            {
                consonant++;
            }
        }

    }
    printf("Vovels: %d, Consonants: %d.\n", vovel, consonant);
}

void countWords(char str[])
{
    int word = 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            word++;
        }
    }
    printf("String has %d words\n", word);
}

void reverseString(char str[])//on str[]
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    for(int i = 0; i < length/2; i++)
    {
        int tmp = str[i];
        str[i] = str[length -1 - i];
        str[length - 1 - i] = tmp;
    }
}

_Bool isPalindrome(char str[])
{
    int length = 0;
    int isPalindrome = 1;
    while(str[length] != '\0')
    {
        length++;
    }
    for(int i = 0; i < length/2; i++)
    {
        if( str[i] != str[length -1 - i])
        {
            isPalindrome = 0;
            break;
        }
    }
    return isPalindrome;
}

void reverseWords(char str[])
{
    char reverse[100];
    int len, i, j, wordStart, wordEnd;
    len = strlen(str);
    j = 0;
    wordStart = len - 1;
    wordEnd   = len - 1;
    while(wordStart > 0)
    {
        if(str[wordStart] == ' ')// If a word is found
        {
            i = wordStart + 1;// Add the word to the reverse string, begin of last word
            while(i <= wordEnd)
            {
                reverse[j] = str[i];
                i++;
                j++;
            }
            reverse[j++] = ' ';
            wordEnd = wordStart - 1;
        }
        wordStart--;
    }
    for(i = 0; i <= wordEnd; i++)//add last word
    {
        reverse[j] = str[i];
        j++;
    }
    reverse[j] = '\0';
    int k = 0;
    while(reverse[k] != '\0')
    {
        str[k] = reverse[k];
        k++;
    }
}

int findFirstCharOccurrence(char str[], const char letter)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == letter)
        {
          return i;
        }
        i++;
    }
    return 0;
}

int findLastCharOccurrence(char str[], char letter)
{
    int i = strlen(str) - 1;
    while(str[i] != -1)
    {
        if(str[i] == letter)
        {
          return i;
        }
        i--;
    }
    return 0;
}

int countCharOccurrence(char str[], char letter)
{
    int count = 0, i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == letter)
        {
          count++;
        }
        i++;
    }
    return count;
}

void printOccurredIndexes(char str[], char letter)
{
    int i = 0;
    printf("Letter occures under indexes:");
    while(str[i] != '\0')
    {
        if(str[i] == letter)
        {
          printf("%d,", i);
        }
        i++;
    }
    printf("\n");
}

void highestFrequencyChar(char str[])
{
    int size = 255, frequency[size];
    int i = 0, max = 0, ascii;
    for(i = 0; i < size; i++)
    {
        frequency[i] = 0;
    }
    i = 0;
    while(str[i] != '\0')
    {
        ascii = (int)str[i];
        frequency[ascii] += 1;
        i++;
    }
    for(i = 0; i < size; i++)
    {
        if(frequency[i] > frequency[max])
        {
            max = i;
        }

    }
    printf("Maximum occurring character is '%c' = %d times.\n", max, frequency[max]);
}

void printCharOccurrences(char str[])
{
    const int size = 255;
    int frequency[size];
    int i = 0, ascii;
    for(i = 0; i < size; i++)
    {
        frequency[i] = 0;
    }
    i = 0;
    while(str[i] != '\0')
    {
        ascii = (int)str[i];
        frequency[ascii] += 1;
        i++;
    }
    for(int i = 0; i < size; i++)
    {
        if(frequency[i] != 0)
        {
            printf("Ascii '%c' occurres %d times.\n", i, frequency[i] );
        }

    }
}

void removeChar(char str[], char letter)
{
    int i = 0;
    int length = strlen(str);
    while(str[i] != '\0')
    {
        if(str[i] == letter)
        {
          int j = i;
          for(int j = i; j < length-1; j++)
          {
              str[j] = str[j+1];
          }
          str[length-1] = '\0';
          break;
        }
        else
        {
            i++;
        }
    }
}

void removeDuplicateLetters(char str[])
{
    int i = 1;
    int len = strlen(str);
    while(str[i] != '\0')
    {
        int isDuplicate = 0;
        for(int j = 0; j < i; j++)
        {
            if(str[i] == str[j])
            {
                isDuplicate = 1;
            }
            if(isDuplicate)
            {
                int k = 0;
                for(k = i; k < len-1; k++)
                {
                    str[k] = str[k+1];
                }
                str[k] = '\0';
                len--, i--;
            }
        }
        i++;
    }
}

void findWord(char str[], char word[])
{
    int i, index = 0, found = 0;
    while(str[index] != '\0')
    {
        if(str[index] == word[0])
        {
            i = 0;
            found = 1;
            while(word[i] != '\0')
            {
                if(str[index + i] != word[i])
                {
                    found = 0;
                    break;
                }
                i++;
            }
        }
        if(found)
        {
            break;
        }
        index++;
    }
    if(found)
    {
        printf("\n'%s' is found at index %d\n.", word, index);
    }
    else
    {
        printf("\n'%s' is not found\n.", word);
    }
}

void findLastWord(char str[], char word[])
{
    int stringLength = strlen(str);
    int wordLength = strlen(word);
    int i, j, index, found;
    index = -1;
    for(i = 0; i <= stringLength - wordLength; i++)
    {
        found = 1;
        for(j = 0; j < wordLength; j++)
        {
            if(str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            index = i;
        }
    }
    if(index == -1)
    {
        printf("\n'%s' not found.\n", word);
    }
    else
    {
        printf("\nLast index of '%s' = %d\n", word, index);
    }
}

void findAllWords(char str[], char word[])
{
    int stringLength = strlen(str);
    int wordLength = strlen(word);
    int i, j, found;
    for(i = 0; i < stringLength - wordLength; i++)
    {
        found = 1;
        for(j = 0; j < wordLength; j++)
        {
            if(str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            printf("'%s' found at index: %d \n", word, i);
        }
    }
}

void countOccurrences(char str[], char word[])
{
    int stringLength = strlen(str);
    int wordLength = strlen(word);
    int i, j, found, count = 0;
    for(i = 0; i < stringLength - wordLength; i++)
    {
        found = 1;
        for(j = 0; j < wordLength; j++)
        {
            if(str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            count++;
        }
    }
    printf("%d occurrences of word '%s'.\n", count, word);
}

void removeFirstOccurrence(char str[], char word[])
{
    int length = strlen(str);
    int wordlength = strlen(word);
    int i, j, found = 0;
    for( i = 0; i < length; i++)
    {
        found = 1;
        for(j = 0; j < wordlength; j++)
        {
            if(str[i+j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            for( j = i; j <= length-wordlength; j++)
            {
                str[j] = str[j + wordlength];
            }
            break;
        }
    }
}

void removeLastOccurrence(char str[], char word[])
{
    int i, j, found, index;
    int strLen = strlen(str);
    int wordLen = strlen(word);
    index = -1;
    for(i = 0; i < strLen - wordLen; i++)
    {
        found = 1;
        for(j = 0; j < wordLen; j++)
        {
            if(str[i+j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            index = i;
        }
    }
    if(index == -1)
    {
        printf("'%s' not found.\n", word);
    }
    else
    {
        for(i = index; i <= strLen - wordLen; i++)
        {
            str[i] = str[i + wordLen];
        }
    }
}

void removeOccurrences(char str[], char word[])
{
    int length = strlen(str);
    int wordlength = strlen(word);
    int i, j, found = 0;
    for( i = 0; i < length; i++)
    {
        found = 1;
        for(j = 0; j < wordlength; j++)
        {
            if(str[i+j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found)
        {
            for( j = i; j <= length-wordlength; j++)
            {
                str[j] = str[j + wordlength];
            }
            length -= wordlength;
            i--;
        }
    }
}

void removeLeadingSpaces(char str[])
{
    int len = strlen(str);
    int count = 0;
    while(str[count] == ' ')
    {
        count++;
    }
    for(int i = 0; i < len - count; i++)
    {
        str[i] = str[i+count];
    }
    str[len-count] = '\0';
}

void removeExtraSpaces(char str[])
{
    int i = 0, j = 0;
    const int len = strlen(str);
    char newString[len];
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            newString[j] = ' ';
            j++;
            while(str[i] == ' ')
            {
                i++;
            }
        }
        newString[j] = str[i];
        i++;
        j++;
    }
    newString[j] = '\0';
    int k = 0;
    for(k = 0; newString[k] != '\0'; k++)
    {
        str[k] = newString[k];
    }
    str[k] = '\0';
}
