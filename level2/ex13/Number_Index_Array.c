#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
	int Number = 0;

	do
	{
		printf("Pleas enter the Number Positive ?\n");
		scanf("%d", & Number);
	
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
void Search_Number_In_Array(int *Arr, int lenght, int NumCheck)
{
	printf("\nPleas enter the Number to Searsh for ?\n");
        scanf("%d", &NumCheck);

	for(int i = 0; i < lenght; i++)
	{
		if(NumCheck == Arr[i])
		{
			printf("\nNumber you are looking For is: %d", Arr[i]);
			printf("\nThe Number found at position : %d\n", i);
			printf("The Number found its Order : %d\n", i + 1);
			return;
		}
	}
	printf("Number You are looking For is: %d", NumCheck);
	printf("\nThe Number is Not found :-(\n\n");
}
void Print_Array(int *Arr, int lenght)
{
	printf("Array Elements is : \n");

	for(int i = 0; i < lenght; i++)
	{
		if((i + 1) != lenght)
			printf("%d, ", Arr[i]);
		else
			printf("%d\n", Arr[i]);
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	Print_Array(Arr, lenght);

	int NumCheck = 0;

	Search_Number_In_Array(Arr, lenght, NumCheck);

	free(Arr);
	return (0);
}
