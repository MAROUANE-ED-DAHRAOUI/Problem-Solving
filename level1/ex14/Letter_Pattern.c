#include <stdio.h>
#include <unistd.h>

int Read_Number_Positive()
{
	int Number = 0;
	
	do
	{
		printf("Pleas enter the Number Positive ?\n");
		scanf("%d", &Number);

	}while(Number < 0);

	return (Number);
}
void Print_letter_Pattern(int nb)
{
	for(int i = 1; i <= nb; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			char ch = 65 + i - 1;
			printf("%c", ch);
		}
		printf("\n");
	}
}
int main()
{
	Print_letter_Pattern(Read_Number_Positive());
	return (0);
}
