#include <stdio.h>
#include <stdlib.h>

int Read_Number_Positive()
{
	int Number = 0;
	
	do
	{
		printf("Pleas enter the Number Positive ?\n");
		scanf("%d", &Number);

	}while(Number <= 0);
	return (Number);
}
int *Array_Element(int Number)
{
	int *Arr = malloc(sizeof(int) * Number + 1);
	
	if(Arr == NULL)
	{
		return (NULL);
	}

	printf("Enter Array Elements :\n\n");
	for(int i = 0; i < Number; i++)
	{
		printf("Element[%d] : ", i);
		scanf("%d", &Arr[i]);
	}

	return (Arr);
}
int Check_Number_Reapeted(int *ptr, int NumCheck, int Number)
{
	int Count = 0;
	for(int i = 0; i < Number; i++)
	{
		if(NumCheck == ptr[i])
		{
			Count++;
		}
	}
	return (Count);
}
void Print_Result(int Number, int *ptr)
{
	int CheckNum = 0;
        printf("Pleas enter the Number you want to check?\n");
        scanf("%d", &CheckNum);

	printf("\nOriginal Array :");
	for(int i = 0; i < Number; i++)
	{
		printf(" %d ", ptr[i]);
	}
	printf("\n%d is Reapeted %d time(s)\n",CheckNum, Check_Number_Reapeted(ptr, CheckNum, Number));
	
}
int main()
{
	int Number = Read_Number_Positive();
	int *Arr = Array_Element(Number);

	if(Arr == NULL)
	{
		printf("Location in memory is faild!!\n");
		return (1);
	}

	Print_Result(Number, Arr);

	free(Arr);
	return (0);
}
