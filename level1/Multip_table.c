#include <stdio.h>
#include <unistd.h>

void Header_Table()
{
	printf("\n\n\t\t\t Multiplication Table From 1 TO 10\n\n");
	for(int i = 1; i <= 10; i++)
	{
		printf("\t%d", i);
	}
	printf("\n----------------------------------------------------------------------------------\n");
}
void Sperator(int n)
{
	if(n <= 9)
	{
		printf("  |\t");
	}
	else
	{
		printf(" |\t");
	}
}
void Multip_table()
{
	Header_Table();
	int i, j;
	for(i = 1; i <= 10; i++)
	{
		printf(" %d", i); Sperator(i);

		for(j = 1; j <= 10; j++)
		{
			printf("%d\t", (i * j));
		}
		printf("\n");
	}
}
void main(void)
{
	Multip_table();
}
