// repeatDivide3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int isDivisible(char *str, int k) {
	int i;
	int sum = (str[0] - '0');
	for (i = 0; str[i] != '\0'; i++) {
		sum += (str[i] - '0');
	}
	return !((sum * k) % 3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char p[11];
	int k;
	printf("Enter an integer: ");
	scanf("%s", &p);
	printf("Enter no.of times to be repeated: ");
	scanf("%d", &k);
	if (isDivisible(p, k))
		printf("Divisible by 3");
	else
		printf("Not divisible by 3");
	getch();
	return 0;
}

