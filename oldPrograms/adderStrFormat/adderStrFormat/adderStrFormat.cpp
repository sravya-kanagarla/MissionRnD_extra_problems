// adderStrFormat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int strLen(char *p) {
	int i;
	for (i = 0; p[i] != '\0'; i++);
	return i;
}

void swap (char *p, char *q) {
	char t;
	t = *p;
	*p = *q;
	*q = t;
}

void strRev(char *p) {
	int i = 0;
	int j = strLen(p) - 1;
	while (i < j) {
		swap(&p[i], &p[j]);
		i++;
		j--;
	}
}

char * adder(char *p, char *q) {
	int lenP = strLen(p) - 1;
	int lenQ = strLen(q) - 1;
	int i = 0;
	char *r;
	int sum = 0;
	if (lenP > lenQ)
		r = (char *) malloc(lenP + 1);
	else
		r = (char *) malloc(lenQ + 1);
	while (lenP >= 0 && lenQ >= 0) {
		 sum += (p[lenP--] - '0') + (q[lenQ--] - '0');
		 r[i++] = (sum % 10) + '0';
		 sum /= 10;
	}
	while (lenP >= 0) {
		sum += (p[lenP--] - '0');
		r[i++] = (sum % 10) + '0';
		sum /= 10;
	}
	while (lenQ >= 0) {
		sum += (q[lenQ--] - '0');
		r[i++] = (sum % 10) + '0';
		sum /= 10;
	}
	if (sum != 0)
		r[i++] = sum + '0';
	r[i] = '\0';
	strRev(r);
	return r;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char p[11];
	char q[11];
	printf("Enter 2 integer: \n");
	scanf("%s%s", &p, &q);
	printf("%s", adder(p, q));
	getch();
	return 0;
}