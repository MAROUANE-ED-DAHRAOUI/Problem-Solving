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
	int *Array = malloc(sizeof(int) * lenght + 1);

	if(Array == NULL)
	{
		return (NULL);
	}
	
	for(int i = 0; i < lenght; i++)
	{
		Array[i] = Random_Number(1, 100);
	}

	return (Array);
}
int Max_in_Array(int *Array, int lenght)
{
	int Max = 0;
	for(int i = 0; i < lenght; i++)
	{
		if(Array[i] > Max)
		{
			Max = Array[i];
		}
	}
	return (Max);
}
void Print_Result(int *Array, int lenght)
{
	printf("\nOriginal Array : ");
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Array[i]);
	}
	putchar('\n');
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	int Max = Max_in_Array(Arr, lenght);

	Print_Result(Arr, lenght);
	
	printf("Max Number is: %d\n", Max);

	free(Arr);
	return (0);
}
