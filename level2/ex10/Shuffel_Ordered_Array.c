#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Read_Number()
{
	int Number = 0;
	
	do
	{
		printf("Pleas enter the Number Of Array lenght?\n");
		scanf("%d", &Number);

	}while(Number <= 0);

	return (Number);
}
int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}
int *Fill_Array(int lenght)
{
	int *Arr = (int *)malloc(sizeof(int) * lenght);

	if(Arr == NULL)
	{
		printf("Error!!\n");
		return (NULL);
	}

	for(int i = 0; i < lenght; i++)
	{
		Arr[i] = (i + 1);
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
void Swap_Number(int *a, int *b)
{
	int Temp = 0;

	Temp = *a;
	*a = *b;
	*b = Temp;
}
void Shuffle_Array(int *Arr, int lenght)
{
	for(int i = 0; i < lenght; i++)
	{
		int index = Random_Number(0, lenght - 1);
		Swap_Number(&Arr[i], &Arr[index]);	
	}	
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
	int *Arr = Fill_Array(lenght);

	printf("\nArray Element Befor Shuffle : \n");
	Print_Array(Arr, lenght);

	Shuffle_Array(Arr, lenght);

	printf("\nArray Element After Shuffle : \n");
	Print_Array(Arr, lenght);

	free(Arr);
	return (0);
}
