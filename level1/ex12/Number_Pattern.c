#include <stdio.h>
#include <unistd.h>

int Read_Positive_Number()
{
	int Number = 0;
	do
	{
		printf("Pleas enter the Number Positive ?: ");
		scanf("%d", &Number);

	}while(Number < 0);
	
	return (Number);
}
void Pattern_Number(int nb)
{
	for(int i = 1; i <= nb; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("%d", i);
		}
		putchar('\n');
	}
}
int main()
{
	Pattern_Number(Read_Positive_Number());
	return (0);
}
