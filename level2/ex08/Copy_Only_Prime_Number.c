#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int Read_Number()
{
    int Number = 0;
    do
    {
        printf("Please enter a positive number: ");
        scanf("%d", &Number);

    } while (Number < 0);

    return Number;
}

int Random_Number(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

int* Fill_Array_With_Random_Number(int length)
{
    int* Arr = (int*)malloc(sizeof(int) * length);

    if (Arr == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        Arr[i] = Random_Number(1, 100);
    }

    return Arr;
}

void Print_Array(int* Arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", Arr[i]);
    }
}

bool Check_Prime_Or_Not(int Number)
{
    if (Number <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= Number; i++)
    {
        if (Number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int* Check_All_Number_In_Array(int* Arr, int length, int* primeArr, int *Count)
{
    for (int i = 0; i < length; i++)
    {
        if (Check_Prime_Or_Not(Arr[i]))
        {
            primeArr[*Count] = Arr[i];
            (*Count)++;
        }
    }

    return (primeArr);
}

int main()
{
    srand((unsigned)time(NULL));

    int length = Read_Number();
    int* Arr = Fill_Array_With_Random_Number(length);
    
    printf("Array Elements: ");
    Print_Array(Arr, length);

    int* Arr2 = (int*)malloc(sizeof(int) * length);
    int Count = 0;
    
    Arr2 = Check_All_Number_In_Array(Arr, length, Arr2, &Count);
    
    printf("\nPrime Numbers In Array 2: ");
    Print_Array(Arr2, Count);

    free(Arr);
    free(Arr2);
    
    return (0);
}
