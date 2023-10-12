#include <stdio.h>
#include <unistd.h>

int Read_Positive_Number()
{
	int Number = 0;

	do
	{
		printf("Pleas enter the Number Positive ? ");
		scanf("%d", &Number);

	}while(Number < 0);

	return (Number);
}
int Reverse_Number(int nb)
{
	int Remainder = 0;
	int Sum = 0;

	while(nb > 0)
	{
		Remainder = nb % 10;
		nb /= 10;

		Sum = Sum * 10 + Remainder;		
	}
	return (Sum);
}
void Check_Number_Palindrom_Or_Not(int nb)
{
	if(nb == Reverse_Number(nb))
	{
		printf("\n%d it's Palindrom Number\n", nb);
	}
	else
	{
		printf("%d it's Not Palindrom Number\n", nb);
	}
}
int main()
{
	Check_Number_Palindrom_Or_Not(Read_Positive_Number());
	return (0);
}
