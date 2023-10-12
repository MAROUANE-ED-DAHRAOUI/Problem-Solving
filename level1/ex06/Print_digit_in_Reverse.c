#include <stdio.h>
#include <unistd.h>

int Reverse_Degit_And_Print(int nb)
{
	int Remainder = 0;
	int Sum = 0;

	while(nb != 0)
	{
		Remainder = nb % 10;
		nb /= 10;
		Sum = Sum * 10 + Remainder; 
	}
	printf("%d\n", Sum);
	return (Sum);
}
int main()
{
	Reverse_Degit_And_Print(1234);
	return (0);
}
