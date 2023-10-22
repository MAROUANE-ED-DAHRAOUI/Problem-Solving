#include <stdio.h>

float Read_Number()
{
	float Number = 0;
	printf("Pleas enter the Number ?\n");
	scanf("%f", &Number);
	
	return (Number);
}
int ft_Round_Number(float Number)
{
	float Remainder = 0;
	Remainder = Number - (int)Number;

	if(Remainder >= 0.5)
	{
		return (Number += 1);
	}
	else if(Remainder <= -0.5)
	{
		return (Number += (-1));
	}
	else
	{
		return (Number);
	}
}
int main()
{
	float Number = Read_Number();
	printf("%d\n", ft_Round_Number(Number));

	return(0);
}
