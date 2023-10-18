#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
	printf("\nArray Elements : \n");
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int Find_Number_Position_In_Array(int *Arr, int lenght, int NumCheck)
{
	for(int i = 0; i < lenght; i++)
	{
		if(NumCheck == Arr[i])
			return (i);
	}
	return (-1);
} 
bool Check_Number(int *Arr, int lenght, int NumCheck)
{
	return (Find_Number_Position_In_Array(Arr, lenght, NumCheck) != -1);
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	Print_Array(Arr, lenght);

	int NumCheck = 0;
	printf("\nPlease enter a number to search for?\n");
	scanf("%d", &NumCheck);

	printf("\nNumber You are looking for is : %d\n", NumCheck);

	if(Check_Number(Arr, lenght, NumCheck))
		printf("Yes, The Number is Found :-)\n");		
	else
		printf("No, the Number is Not found :-(\n");
	

	free(Arr);
	return (0);
}
