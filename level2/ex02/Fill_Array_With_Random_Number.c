#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Options {CapitaLett = 1, SmallLett = 2, Digit = 3, SpecialChara = 4};

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
int *Fill_Array_With_Random_Number(int Number)
{
	int *Arr = malloc((sizeof(int)) * Number + 1);

	if(Arr == NULL)
	{
		return (NULL);
	}

	for(int i = 0; i < Number; i++)
	{
		Arr[i] = Random_Number(1, 100);
	}

	return (Arr);
}
void Print_Array(int Number, int Arr[])
{
	printf("\nArray Elements : ");
	for(int i = 0; i < Number; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int main()
{
	srand((unsigned)time(NULL));

	int Number = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(Number);
	
	if(Arr == NULL)
	{
		printf("Error!\n");
		return (1);
	}	

	Print_Array(Number, Arr);
	free(Arr);

	return (0);
}	
