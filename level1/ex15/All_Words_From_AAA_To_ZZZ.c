#include <stdio.h>
#include <unistd.h>

void Print_All_Words()
{
	for(char i = 65; i <= 90; i++)
	{
		for(char j = 65; j <= 90; j++)
		{
			for(char k = 65; k <= 90; k++)
			{
				printf("%c%c%c\n", i, j, k);
			}
		}
	}
} 
int main()
{
	Print_All_Words();
	return (0);
}
