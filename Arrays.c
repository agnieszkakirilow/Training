#include<stdio.h>

void inputIntoArray(int arr[], int value, int position);
void printArray(int arr[]);
void printWholeArray(int arr[]);
void checkFrequency(int arr[]);
void printUnique(int arr[]);
int countDuplicates(int arr[]);
void deleteDuplicates(int arr[]);
void merge(int arr[], int arr2[]);
void reverseArray(int arr[]);
void evenOdd(int arr[]);
void searchElement(int arr[], int element);
void sortArray(int arr[]);
void leftRotate(int arr[], int rotation);
void rightRotate(int arr[], int rotation);

int main()
{
    int arr[20] = {5,22,14,22,3,5,5,14,22,22};
    printWholeArray(arr);
    printArray(arr);
    inputIntoArray(arr,24,3);
    printArray(arr);
    checkFrequency(arr);
    printUnique(arr);
    printf("Duplicates number: %d\n",countDuplicates(arr));
    deleteDuplicates(arr);
    printArray(arr);
    int arr2[20] = {7,2,4,56,1,12,14,17,18,11,5,4};
    merge(arr, arr2);
    printArray(arr2);
    reverseArray(arr2);
    printArray(arr2);
    evenOdd(arr2);
    searchElement(arr2,11);
    searchElement(arr2, 13);
    sortArray(arr2);
    leftRotate(arr2, 3);
    rightRotate(arr2,3);
    return 0;
}

void inputIntoArray(int arr[], int value, int position)
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    printf("input into array\n");
    for(int i = size; i > position-1; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[position-1] = value;
    for(int i = 0; i < size + 1; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void printArray(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    printf("Print array\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void printWholeArray(int arr[])
{
    printf("Print whole array\n");
    for(int i = 0; i < 20; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void checkFrequency(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int freq[size];
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        count = 1;
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
        freq[i] = count;
        }
     }
     for(int i = 0; i < size; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }
}

void printUnique(int arr[])
{

    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int freq[size];
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        count = 1;
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
        freq[i] = count;
        }
     }
     printf("Uniques are: ");
     for(int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d, freq[%d] = %d\n",i,arr[i],i,freq[i]);
        if(freq[i] == 1)
        {
            printf("%d   ", arr[i]);
        }
    }
    printf("\n");
}

int countDuplicates(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void deleteDuplicates(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int newsize = size;
    for(int i = 0; i < newsize; i++)
    {
        for(int j = i+1; j < newsize; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < newsize-1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                newsize--;
                j--;
            }
        }
    }
}

void merge(int arr[], int arr2[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int size2 = 0;
    while(arr2[size2] != 0)
    {
        size2++;
    }
    int size3 = size + size2;
    int arr3[size3];
    for(int i = 0; i < size; i++)
    {
        arr3[i] = arr[i];
    }
    int k = 0;
    for(int i = size, k = 0; i < size3; i++, k++)
    {
        arr3[i] = arr2[k];
    }
    for(int i = 0; i < size3; i++)
    {
        printf("%d   ", arr3[i]);
    }
    printf("\n");
}

void reverseArray(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    for(int i = 0; i < size/2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = tmp;
    }
}

void evenOdd(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    int arrEven[size];
    int arrOdd[size];
    int iEven = 0;
    int iOdd = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i]%2 == 0)
        {
            arrEven[iEven] = arr[i];
            iEven++;
        }
        else
        {
            arrOdd[iOdd] = arr[i];
            iOdd++;
        }
    }
    printf("Even elements:");
    for(int i = 0; i < iEven; i++)
    {
        printf("%d   ", arrEven[i]);
    }
    printf("\n");
    printf("Odd elements:");
    for(int i = 0; i < iOdd; i++)
    {
        printf("%d   ", arrOdd[i]);
    }
    printf("\n");
}

void searchElement(int arr[], int element)
{
    _Bool isPresent = 0;
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            isPresent = 1;
            break;
        }
    }
    isPresent?printf("Element in the array\n"):printf("Element not in the array\n");
}

void sortArray(int arr[])
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    for(int i = 0; i < size; i++)
    {
        int min = arr[i];
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < min)
            {
                int tmp = arr[j];
                arr[j] = min;
                min = tmp;
            }
        }
        arr[i] = min;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void leftRotate(int arr[], int rotation)
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    for(int j = 1; j <= rotation; j++)
    {
        int tmp = arr[0];
        for(int i = 0; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        arr[size - 1] = tmp;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void rightRotate(int arr[], int rotation)
{
    int size = 0;
    while(arr[size] != 0)
    {
        size++;
    }
    for(int j = 1; j <= rotation; j++)
    {
        int tmp = arr[size-1];
        for(int i = size-1; i >= 0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}
