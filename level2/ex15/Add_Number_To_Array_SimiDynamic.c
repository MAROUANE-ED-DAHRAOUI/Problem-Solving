#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Read_Number()
{
	int Number = 0;
	
	do
	{
		printf("Pleas enter the Number? : ");
		scanf("%d", &Number);

	}while(Number <= 0);
	
	return (Number);
}
bool Add_Number_Or_Not()
{	
	int Number = 1;

	printf("Do You want to add more Numbers? [0]:No,[1]:Yes : ");
	scanf("%d", &Number);
	
	return (Number == 1);
}
int *Add_Number()
{
	int Number = 0;
	int *Arr = NULL;
	int Count = 0;

	Number = Read_Number();
	Arr = (int *)malloc(sizeof(int));
	Arr[Count] = Number;

	while(Add_Number_Or_Not())
	{
		Count++;
		Arr = (int *)realloc(Arr, (Count + 1) * sizeof(int));

		Number = Read_Number();
		Arr[Count] = Number;
	}

	Count += 1;
	Arr[Count] = '\0';
	printf("\nArray lenght : %d\n", Count);

	return (Arr);
}
void Print_Array(int *Arr)
{
	printf("Array Elements : ");
	for(int i = 0; Arr[i] != '\0'; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int main()
{
	int *Arr = Add_Number(Arr);
	Print_Array(Arr);

	free(Arr);
	return(0);
}
