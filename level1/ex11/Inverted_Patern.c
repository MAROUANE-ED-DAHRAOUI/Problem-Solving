#include <stdio.h>
#include <unistd.h>

int Read_Number_Positive()
{
	int Number = 0;
	do
	{
		printf("Pleas enter the Number Positive ?: ");
		scanf("%d", &Number);

	}while(Number < 0);

	return (Number);
}
void Inverted_Patern(int nb)
{
	for(int i = nb; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			printf("%d", i);
		}
		putchar('\n');
	}
}
int main()
{
	Inverted_Patern(Read_Number_Positive());
	return (0);
}
