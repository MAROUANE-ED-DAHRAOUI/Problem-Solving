#include <stdio.h>
#include <stdbool.h>

bool check_Perfect(int nb)
{
	int Sum = 0;
	for(int i = 1; i < nb; i++)
	{
		if(nb % i == 0)
		{
			Sum += i;	
		}
	}
	printf("%d\n", Sum);

	return (Sum == nb);
}
void Print_Result(int nb)
{
	if(check_Perfect(nb))
	{
		printf("%d is Perfect.\n", nb);
	}
	else
	{
		printf("%d is not Perfect.\n", nb);
	}
}
int main()
{
	Print_Result(28);
	Print_Result(12);
	Print_Result(16);
	Print_Result(23);
	return (0);
}
