#include <stdio.h>
#include <stdlib.h>

int *Fill_Array()
{
	int *Arr = malloc(sizeof(int) * 11);
	
	if(Arr == NULL)
	{
		return NULL;
	}

	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 50;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;
	Arr[9] = 90;
	Arr[10] = 0;

	return (Arr);
}
int *Copy_Distinct_Numbers_In_Another_Array(int *Arr)
{
	int *Arr2 = malloc(sizeof(int) * 10);
	if(Arr2 == NULL)
	{
		return (NULL);
	}
	int i = 0;
	int j = 0;

	while(Arr[i] != '\0')
	{
		if(Arr[i] != Arr[i + 1])
		{
			Arr2[j] = Arr[i];
			j++;
		}
		i++;
	}
	
	return(Arr2);
}
void Print_Array(int *Arr)
{
	for(int i = 0; Arr[i] != '\0'; i++)
	{
		printf("%d ", Arr[i]);
	}
	putchar('\n');
}
int main()
{
	int *Arr = Fill_Array();
	int *Arr2 = Copy_Distinct_Numbers_In_Another_Array(Arr);
	
	printf("Array 1 Elements : ");
	Print_Array(Arr);

	printf("Array 2 Distinct Elements : ");
        Print_Array(Arr2);

	free(Arr);
	free(Arr2);

	return(0);
}
