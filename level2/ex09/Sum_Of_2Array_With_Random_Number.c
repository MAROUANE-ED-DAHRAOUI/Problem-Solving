#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
	int Number = 0;
	
	do
	{
		printf("Pleas enter the Number Positive?\n");
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
void Print_Array(int *Arr, int lenght)
{
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int *Sum_Arrays_To_Another_Array(int *Arr, int *Arr2, int lenght)
{
	int *ArrSum = (int *)malloc(sizeof(int) * lenght + 1);

	if(ArrSum == NULL)
	{
		return (NULL);
	}

	for(int i = 0; i < lenght; i++)
	{
		ArrSum[i] = Arr[i] + Arr2[i];
	}
	return (ArrSum);	
}
int main()
{
	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	int *Arr2 = malloc(sizeof(int) * lenght + 1);
	
	if(Arr2 == NULL)
	{
		return (0);
	}

	Arr2 = Fill_Array_With_Random_Number(lenght);

	printf("\nArray 1 Element : \n");
	Print_Array(Arr, lenght);
	
	printf("\nArray 2 Element : \n");	
	Print_Array(Arr2 ,lenght);

	int *ArrSum = Sum_Arrays_To_Another_Array(Arr, Arr2, lenght);
	printf("\nSum Of Array 1 and Array 2 Element : \n");
	Print_Array(ArrSum, lenght);

	free(Arr);
	free(Arr2);
	free(ArrSum);

	return (0);
}
