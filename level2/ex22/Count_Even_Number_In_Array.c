#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
        int Number = 0;
        do
        {
                printf("Pleas enter the Number Positive ?\n");
                scanf("%d", &Number);

        }while(Number <= 0);

        return (Number);
}
int Random_Number(int From, int To)
{
        int RandNum = rand() % (To - From + 1) + From;
        return (RandNum);
}
int *Fill_Array_With_Random_Number(int lenght)
{
        int *Arr = (int *)malloc(sizeof(int) * lenght + 1);

        if(Arr == NULL)
        {
                return (NULL);
        }

        for(int i = 0; i < lenght; i++)
        {
                Arr[i] = Random_Number(1, 100);
        }

        return (Arr);
}
int Count_Odd_Number_In_Array(int *Arr, int lenght)
{
        int Count = 0;
        for(int i = 0; i < lenght; i++)
        {
                if(Arr[i] % 2 == 0)
                {
                        Count++;
                }
        }
        return(Count);
}
void Print_Array(int *Arr, int lenght)
{
        printf("Array Elements: ");
        for(int i = 0; i < lenght; i++)
        {
                printf("%d ", Arr[i]);
        }
        putchar('\n');
}
int main()
{
        int lenght = Read_Number();
        int *Arr = Fill_Array_With_Random_Number(lenght);
        Print_Array(Arr, lenght);

        int Count = Count_Odd_Number_In_Array(Arr, lenght);
        printf("Odd Numbers Counts Is : %d\n", Count);

        free(Arr);
        return (0);
}
