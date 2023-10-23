#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float Read_Number()
{
	float Number = 0;
	
	printf("Pleas enter the Number ?\n");
	scanf("%f", &Number);
	
	return (Number);
}
float Fraction_Part(float Number)
{
	return (Number - (int)Number);
}
int My_Ceil_Number(float Number)
{
	float Fract = Fraction_Part(Number);
	float FractAbs = fabs(Fract);
	
	if(FractAbs > 0)
	{
		if(Number > 0)
		{
			return ((int)Number + 1);
		}
		else
		{
			return ((int)Number);
		}
	}
	else
	{
		return (Number);
	}
}
int main()
{
	float Number = Read_Number();

	printf("My Ceil Result : %d\n", My_Ceil_Number(Number));
	printf("C Function Ceil Result : %f\n", ceil(Number));
	
	return (0);
}
