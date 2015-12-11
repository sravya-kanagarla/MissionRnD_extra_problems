// divide11.cpp : Defines the entry pobint for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int isDivisible(char *str) {
	int i = 0;
	int sum = 0;
	while (str[i] != '\0') {
		if (i % 2)
			sum += (str[i] - '0');
		else
			sum -= (str[i] - '0');
		if (sum >= 11)
			sum -= 11;
		i++;
	}
	return !(sum);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[11];
	printf("Enter an integer: ");
	scanf("%s", str);
	if (isDivisible(str))
		printf("%s is divisible by 11", str);
	else
		printf("%s is not divisible by 11", str);
	getch();
	return 0;
}

