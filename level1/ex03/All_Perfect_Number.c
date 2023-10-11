#include <stdio.h>
#include <stdbool.h>

bool Is_Perfect(int nb)
{
	int Sum = 0;
	for(int i = 1; i < nb; i++)
	{
		if(nb % i == 0)
		{
			Sum += i;
		}
	}
	return (Sum == nb);
}
void Print_Perfect_Number_From1_to_N(int nb)
{
	for(int i = 1; i <= nb; i++)
	{
		if(Is_Perfect(i))
		{
			printf("%d\n", i);
		}
	}
}
int main()
{
	Print_Perfect_Number_From1_to_N(500);
	return (0);
}
