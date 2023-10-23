#include <stdio.h>
#include <math.h>

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
int My_Sqrt_Number(int Number)
{
	int i = 1;
	if(Number < 0)
	{
		return (-1);
	}

	while((i * i) <= Number)
	{
		if((i * i) == Number)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
int main()
{
	int Number = Read_Number_Positive();
	int Result = My_Sqrt_Number(Number);
	
	if(Result != -1)
	{
		printf("My MySqrt Result : %d\n", Result);
               	printf("C sqrt function Result : %f\n", sqrt(Number));
	}
	else
	{
		printf("No integer Sqrt for Number %d\n", Number);
	}
	return (0);
}
