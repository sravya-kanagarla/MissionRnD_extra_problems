// repeatDivide11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int isDivisible(char *str, int k) {
	int i = 0;
	int evenSum = 0;
	int oddSum = 0;
	int es = 0;
	int os = 0;
	while (str[i] != '\0') {
		if (i % 2)
			oddSum += (str[i] - '0');
		else
			evenSum += (str[i] - '0');
		i++;
	}
	if (i % 2) {
		while (k > 0) {
			if(k % 2) {
				os += oddSum;
				es += evenSum;
			} else {
				es += oddSum;
				os += evenSum;
			}
			k--;
		}
	} else {
		es = evenSum * k;
		os = oddSum * k;
	}
	return !((es - os) % 11);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char p[11];
	int k;
	printf("Enter an integer: ");
	scanf("%s", &p);
	printf("Enter an integer to be repeated: ");
	scanf("%d", &k);
	if (isDivisible(p, k))
		printf("Divisible by 11");
	else
		printf("Not divisible by 11");
	getch();
	return 0;
}