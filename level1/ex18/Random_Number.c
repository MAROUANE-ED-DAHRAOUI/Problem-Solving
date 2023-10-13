#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}

int main()
{
	srand((unsigned) time (NULL));

	printf("%d\n", Random_Number(1, 10));
	return (0);
}	
