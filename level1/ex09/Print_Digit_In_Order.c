#include <stdio.h>

int Reverse_Number(int nb)
{
	int Remainder = 0, Sum = 0;
	while(nb > 0)
	{
		Remainder = nb % 10;
		nb /= 10;

		Sum = (Sum * 10) + Remainder;
	}
	return (Sum);
}
void Print_digit_From_Left_To_Right(int Number)
{
	int Remainder = 0;
	Number = Reverse_Number(Number);
	
	while(Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
	
		printf("%d\n", Remainder);
	}
}
int main()
{
	Print_digit_From_Left_To_Right(12345);
	return (0);
}
