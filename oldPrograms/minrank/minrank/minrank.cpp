// program3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

/* Find the min rank of a given number */

int factorial(unsigned int n) {
	int fact;
	for (fact = 1; n >= 2; n--) {
		fact *= n;
	}
	return fact;
}

int findLen(unsigned int n) {
	int i;
	for (i = 0; n > 0; i++) {
		n /= 10;
	}
	return i;
}

int small(unsigned int n, int index) {
	int p;
	int k = index;
	int count = 0;
	for (p = 1; k > 0; k--) 
		p *= 10;
	k = (n / p) % 10;
	for (p = 0; index != p; p++) {
		if (k > (n % 10)) {
			count++;
		}
		n /= 10;
	}
	return count;
}

int repetition(unsigned int n) {
	int count = 1;
	int i;
	int a[10];
	for (i = 0; i < 10; i++)
		a[i] = 0;
	while (n > 0) {
		a[n % 10]++;
		n /= 10;
	}
	for (i = 0; i < 10; i++) {
		if (a[i] > 1) {
			count *= factorial(a[i]);
		}
	}
	return count;
}

int minRank(unsigned int n) {
	int rank = 0;
	int length = findLen(n);
	int i;
	for (i = length - 1; i > 0; i--) {
		rank += (small(n, i) * factorial(i));
	}
	if ((i = repetition(n)) && rank > i) {
			rank /= i;
	}
	return rank;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("Min rank of %d is %d", n, minRank(n));
	getch();
	return 0;
}