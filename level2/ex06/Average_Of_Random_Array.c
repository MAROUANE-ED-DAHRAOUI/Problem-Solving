#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
	int Number = 0;

	do
	{
		printf("Pleas enter the Number of Array lenght?\n");
		scanf("%d", &Number);

	}while(Number < 0);
	return (Number);
}
int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}
int *Fill_Array_With_Random_Numbers(int lenght)
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
int Sum_Elements_Array(int *Ptr, int lenght)
{
	int Sum = 0;
	for(int i = 0; i < lenght; i++)
	{
		Sum += Ptr[i];
	}
	return (Sum);
}
float Average_Array(int *Ptr, int lenght)
{
	return (Sum_Elements_Array(Ptr, lenght) / lenght);
}
void Print_Result(int *Ptr, int lenght)
{
	printf("Elements Array : ");
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Ptr[i]);
	}
	putchar('\n');
}
int main()
{
	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Numbers(lenght);
	Print_Result(Arr, lenght);

	float Average = Average_Array(Arr, lenght);
	printf("Average Of all Numbers In Array Is : %2f\n", Average);

	free(Arr);
	return (0);
}
