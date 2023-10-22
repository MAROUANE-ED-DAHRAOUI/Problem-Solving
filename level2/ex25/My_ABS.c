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
float My_Abs_Result(float Number)
{
	if(Number < 0)
	{
		Number *= -1;
	}

	return (Number);		
}
int main()
{
	float Number = Read_Number();

	printf("My ABS Result : %f\n", My_Abs_Result(Number));
	
	float x = abs(Number);
	printf("C My ABS Result : %f\n", x);
	
	return (0);
}
