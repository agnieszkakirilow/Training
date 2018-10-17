#ifndef STRINGSPRO_H_INCLUDED
#define STRINGSPRO_H_INCLUDED

void printString(char str[]);
void lowerToUpper(char str[]);
void toggleString(char str[]);
void countSigns(char str[]);
void countVovels(char str[]);
void countWords(char str[]);
void reverseString(char str[]);
_Bool isPalindrome(char str[]);
void reverseWords(char str[]);
int findFirstCharOccurrence(char str[], char letter);
int findLastCharOccurrence(char str[], char letter);
int countCharOccurrence(char str[], char letter);
void printOccurredIndexes(char str[], char letter);
void highestFrequencyChar(char str[]);
void printCharOccurrences(char str[]);
void removeChar(char str[], char letter);
void removeDuplicateLetters(char str[]);
void findWord(char str[], char word[]);
void findLastWord(char str[], char word[]);
void findAllWords(char str[], char word[]);
void countOccurrences(char str[], char word[]);
void removeFirstOccurrence(char str[], char word[]);
void removeLastOccurrence(char str[], char word[]);
void removeOccurrences(char str[], char word[]);
void removeLeadingSpaces(char str[]);
void removeExtraSpaces(char str[]);
#endif // STRINGSPRO_H_INCLUDED
