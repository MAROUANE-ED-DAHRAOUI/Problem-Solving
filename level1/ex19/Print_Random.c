#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum options {Capital = 1, Small = 2, Digit = 3, SpecialChar = 4};

int  Random_Number(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;
	return (randNum);
}
char getRandomNumber(enum options charType)
{
	switch (charType)
	{
	case Capital:
		return (char)Random_Number(65, 90);

	case Small:
		return (char)Random_Number(97, 122);

	case Digit:
		return (char)Random_Number(48, 57);
	case SpecialChar:
		return (char)Random_Number(33, 47);
	default:
		return ('\0');
	}
}
int main()
{
	srand((unsigned)time(NULL));

	printf("%c\n", getRandomNumber(Capital));
	printf("%c\n", getRandomNumber(Small));
	printf("%c\n", getRandomNumber(Digit));
	printf("%c\n", getRandomNumber(SpecialChar));

	return (0);
		
}
