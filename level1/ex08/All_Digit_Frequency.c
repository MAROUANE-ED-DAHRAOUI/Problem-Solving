#include <stdio.h>
#include <unistd.h>

int Count_Digit_Freq(int nb, int FreCount)
{
	int Count = 0, Remainder = 0;

	while(nb > 0)
	{
		Remainder = nb % 10;
		nb /= 10;

		if(Remainder == FreCount)
		{
			Count++;
		}
	}
	return (Count);
}
void Check_Digit(int nb)
{
	for(int i = 0; i <= 9; i++)
	{
		int Sum = 0;

		Sum = Count_Digit_Freq(nb, i);

		if(Sum > 0)
		{
			printf("Digit %d Frequency is %d Time(s)\n", i, Sum);
		}
	}
}
int main()
{
	int nb = 1211334322;
	Check_Digit(nb);

	return (0);
}
