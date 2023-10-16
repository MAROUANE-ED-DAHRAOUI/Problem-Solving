#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
        int Number = 0;
        do
        {
                printf("Pleas enter the lenght of Array?\n");
                scanf("%d", &Number);

        }while(Number < 0);

        return (Number);
}
int Random_Number(int From, int To)
{
        int RandNum = rand() % (To - From + 1) + From;
        return (RandNum);
}
int *Fill_Array_With_Random_Number(int lenght)
{
        int *Arr = malloc(sizeof(int) * lenght + 1);

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
int Sum_Numbers_In_Array(int *Ptr, int lenght)
{
        int Sum = 0;
        for(int i = 0; i < lenght; i++)
        {
                Sum += Ptr[i];
        }
        return (Sum);
}
void Print_Result(int *Ptr, int lenght)
{
        printf("Array Element : ");
        for(int i = 0; i < lenght; i++)
        {
                printf("%d ", Ptr[i]);
        }
        putchar('\n');
}
int main()
{
        int lenght = Read_Number();

        int *Arr = Fill_Array_With_Random_Number(lenght);
        Print_Result(Arr, lenght);

        int Sum = Sum_Numbers_In_Array(Arr, lenght);
        printf("Sum Of all Numbers is : %d\n", Sum);

        free(Arr);
        return (0);
}
