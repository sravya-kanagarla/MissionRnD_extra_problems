// baseMinus2Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int strLen(char *str) {
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

char* generateNum(int n) {
	char *str = (char *) malloc(32);
	int i;
	int d;
	for(i = 0; n / 2 != 0; i++) {
		d = n % -2;
		if (d == -1) {
			str[i] = '1';
			n /= -2;
			n++;
		} else {
			str[i] = d + '0';
			n /= -2;
		}
	}
	if (n != 0) {
		str[i++] = '1';
		if (n == -1)
			str[i++] = '1';
	}
	str[i] = '\0';
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int i;
	char * str;
	printf("Enter an integer: ");
	scanf("%d", &n);
	str = generateNum(n);
	for (i = strLen(str) - 1; i >= 0; i--)
		printf("%c", str[i]);
	getch();
	return 0;
}