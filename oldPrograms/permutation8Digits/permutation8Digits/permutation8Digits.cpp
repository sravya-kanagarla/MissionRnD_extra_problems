// permutation8Digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int factorial(unsigned int n) {
	int fact;
	for (fact = 1; n >= 2; n--) {
		fact *= n;
	}
	return fact;
}

int small(unsigned int n, int index) {
	int p;
	int k = index;
	int count = 0;
	for (p = 1; k > 0; k--) 
		p *= 10;
	k = (n / p) % 10;
	for (p = 0; index != p; p++) {
		if (k >= (n % 10)) {
			count++;
		}
		n /= 10;
	}
	return count;
}

int minRank(unsigned int n) {
	int rank = 0;
	int i;
	for (i = 7; i > 0; i--) {
		rank += (small(n, i) * factorial(i));
	}
	return rank;
}

int * makeArray (unsigned int n) {
	int *a;
	a = (int *) malloc(sizeof(int) * 8);
	int i;
	for (i = 0; n > 0; i++) {
		a[i] = n % 10;
		n /= 10;
	}
	return a;
}

unsigned int makeNum(int *a) {
	unsigned int res = 0;
	int i;
	for (i = 0; i < 8; i++) {
		res = res * 10 + a[i];
	}
	return res;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutations(int *a, int left, int right, unsigned int *res) {
	int i;
	unsigned int n;
	if (left == right) {
		n = makeNum(a);
		res[minRank(n)] = n;
	} else {
		for (i = left; i <= right; i++) {
 			swap(&a[left], &a[i]);
			permutations(a, left + 1, right, res);
			swap(&a[left], &a[i]);
		}
	}
}

unsigned int * findPermutation(unsigned int n) {
	unsigned int *res;
	int *a;
	res = (unsigned int *) malloc(sizeof(unsigned int) * 40320);
	a = makeArray(n);
	permutations(a, 0, 7, res);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int x;
	unsigned int *res;
	int i;
	printf("Enter an integer: ");
	scanf("%d", &x);
	res = findPermutation(x);
	for (i = 0; i < 40320; i++)
		printf("%d\n", res[i]);
	getch();
	return 0;
}

