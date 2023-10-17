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
void Print_Array(int *Arr, int lenght)
{
	for(int i = 0; i < lenght; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int *Copy_Array_In_Reverse(int *Arr, int lenght)
{
	int *Arr2 = (int *)malloc(sizeof(int) * lenght + 1);
	
	if(Arr2 == NULL)
	{
		printf("Error!!\n");
		return (NULL);
	}

	int i = 0;

	while(lenght > 0)
	{
		Arr2[i] = Arr[lenght - 1];
		lenght--;
		i++;
	}
	return (Arr2);
}
int main()
{
	srand((unsigned)time(NULL));

	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	
	printf("\nArray Elemnts Before Copy : \n");
	Print_Array(Arr, lenght);

	int *Arr2 = Copy_Array_In_Reverse(Arr, lenght);
	printf("\nArray 2 Element After Copying Array 1 In Reverse Order : \n");
	Print_Array(Arr2, lenght);

	free(Arr);
	free(Arr2);

	return (0);
}
