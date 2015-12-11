// modulo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int calc(unsigned int x, unsigned int y, unsigned int z) {
	int ans = 1;
	int temp = x % z;
	while (y > 0) {
		if (y & 1) {
			ans = (temp * ans) % z;
		}
		temp = (temp * temp) % z;
		y >>= 1; 
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int x;
	unsigned int y;
	unsigned int z;
	printf("Enter three integers: \n");
	scanf("%d%d%d", &x, &y, &z);
	printf("Result: %d", calc(x, y, z));
	getch();
	return 0;
}

