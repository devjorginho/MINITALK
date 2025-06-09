#include<stdio.h>

int main()
{
	char num = 0b11001111;

	int shift = 7;
	while (shift >= 0)
	{
		printf("%d", (num >> shift) & 0b00000001);
		shift--;
	}
}