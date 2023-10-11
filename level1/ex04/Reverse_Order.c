#include <stdio.h>

void Reverse_Order(int nb)
{
	int mod = 0;
	while(nb != 0)
	{
		mod = nb % 10;
		nb /= 10;

		printf("%d\n", mod);
	}
}
int main()
{
	Reverse_Order(1234);
}
