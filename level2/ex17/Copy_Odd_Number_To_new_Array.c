#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
	int Number = 0;
	do
	{
		printf("Pleas enter the Number ?\n");
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
	int *Arr = malloc(sizeof(int) * lenght);
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
void Add_Array_Element(int Number, int **Arr2, int *Arrlenght)
{
	*Arrlenght += 1;
	(*Arr2)[*Arrlenght - 1] = Number;
}
int *Copy_Only_Odd_Number_In_Another_Array(int *Arr, int lenght, int *Arr2lenght)
{
	int *Arr2 = malloc(sizeof(int) * lenght);
	if(Arr2 == NULL)
	{
		printf("Error!!\n");
		return (NULL);
	}
	*Arr2lenght = 0;

	for(int i = 0; i < lenght; i++)
	{
		if(Arr[i] % 2 != 0)
		{
			Add_Array_Element(Arr[i], &Arr2, Arr2lenght);
		}
	}
	return (Arr2);
}
void Print_Array(int *Arr, int lenght)
{
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
 	int Arr2lenght = 0;
	int *Arr = Fill_Array_With_Random_Number(lenght);
	int *Arr2 = Copy_Only_Odd_Number_In_Another_Array(Arr, lenght, &Arr2lenght);

	printf("\nArray Elements : ");
	Print_Array(Arr, lenght);
	
	printf("Array Element After Copy Odd Number : ");
	Print_Array(Arr2, Arr2lenght);

	free(Arr);
	free(Arr2);
	
	return (0);
}
