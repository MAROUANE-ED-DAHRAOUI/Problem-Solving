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

	}while(Number < 0);

	return (Number);
}
int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + 1;
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
int *ft_Numcpy(int *dest, int *src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int main()
{
	int lenght = Read_Number();
	int *Arr = Fill_Array_With_Random_Number(lenght);
	printf("Array Elements : ");
	Print_Array(Arr, lenght);
	
	int *Arr2 = malloc(sizeof(int) * lenght + 1);
		Arr2 = ft_Numcpy(Arr2, Arr);
	printf("\nArray 2 Elements After Copy : ");
	Print_Array(Arr2, lenght);

	free(Arr);
	free(Arr2);
	return (0);
}
