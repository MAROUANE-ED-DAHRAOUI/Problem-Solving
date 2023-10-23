#include <stdio.h>
#include <math.h>

float Read_Number()
{
	float Number = 0;
	
	printf("Pleas enter the Number ?\n");
	scanf("%f", &Number);

	return (Number);
}
int My_Floor_Number(float Number)
{
	if(Number >= 0)
	{
		return ((int)Number);
	}
	else
	{
		return ((int)Number - 1);
	}
}
int main()
{
	float Number = Read_Number();
	printf("My Myfloor Result: %d\n", My_Floor_Number(Number));

	int Result = floor(Number);
	printf("C floor Function Result: %d\n", Result);
	
	return (0);
}
