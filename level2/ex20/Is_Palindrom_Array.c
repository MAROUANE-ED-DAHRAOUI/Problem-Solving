#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *Fill_Array()
{
	int *Arr = malloc(sizeof(int) * 7);
	if(Arr == NULL)
	{
		return (NULL);
	}

	Arr[0] = 10;
	Arr[1] = 50;
	Arr[2] = 30;
	Arr[3] = 30;
	Arr[4] = 50;
	Arr[5] = 10;
	Arr[6] = '\0';

	return (Arr);
}
int ft_strlen(int *Arr)
{
        int i = 0;
        while(Arr[i] != '\0')
        {
                i++;
        }
        return (i);
}
bool Is_Palindrom(int *Arr)
{
	int len = ft_strlen(Arr);

	for(int i = 0; i < len; i++)
	{
		if(Arr[i] != Arr[len - i - 1])
		{
			return (false);
		}
	}
	return (true);
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

	printf("Array Elements : \n");
	Print_Array(Arr);

	if(Is_Palindrom(Arr) == true)
	{
		printf("Yes, Array Is Palindrom \n");
	}
	else
	{
		printf("No, Array Is Not Palindrom!! \n");
	}

	free(Arr);
	return (0);
}
