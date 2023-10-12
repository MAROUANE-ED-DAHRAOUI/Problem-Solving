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
void Inverted_letter_Pattern(int nb)
{
	for(int i = nb; i >= 1; i--)
	{
		for(int j = 1; j <= i; j++)
		{
			char c = 'A'+ i - 1;

			printf("%c", c);
		}
		putchar('\n');
	}
	
}
int main()
{
	Inverted_letter_Pattern(Read_Number_Positive());
	return (0);
}
