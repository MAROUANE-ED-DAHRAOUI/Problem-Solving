#include <stdio.h>
#include <unistd.h>

int Digit_frequency(int SearchNum, int nb)
{
	int Count = 0;
	int Remain = 0;

	while(nb > 0)
	{
		Remain = nb % 10;
		nb /= 10;

		if(SearchNum == Remain)
		{
			Count++;
		}
	}
	return (Count);	
}
int main()
{	
	printf("Digit %d Frequency is %d Time(s)\n", 1, Digit_frequency(1, 11233111));
	
	return (0);
}
