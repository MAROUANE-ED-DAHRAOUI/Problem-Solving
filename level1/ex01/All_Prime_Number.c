#include <stdio.h>
#include <stdbool.h>

bool Prime_Number(int nb)
{
	for(int i = 2; i <= nb / 2; i++)
	{
		if(nb % i == 0)
			return (0);
	}
	return (1);
}
void All_Prime(int nb)
{
	for(int i = 1; i <= nb; i++)
	{	
		if(Prime_Number(i) == 1)
		{
			printf("%d ", i);
		}
	}	
}
int main()
{
	All_Prime(20);
	return (0);
}
