#include <stdio.h>

int Sum_Of_Degit(int nb)
{
	int Sum = 0;
	int mod = 0;
	while(nb != 0)
	{
		mod = nb % 10;
		nb /= 10;
		Sum += mod;
	}
	return (Sum);
}
int main()
{
	printf("%d\n", Sum_Of_Degit(1234));
}
