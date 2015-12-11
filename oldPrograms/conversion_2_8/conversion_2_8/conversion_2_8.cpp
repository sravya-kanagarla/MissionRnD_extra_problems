// conversion_2_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Base -2 to -8 */

int pow(int x) {
	int res = 1;
	while (x > 0) {
		res *= -2;
		x--;
	}
	return res;
}

int conversion(char *x, int n) {
	int i = 0;
	int q = 0;
	int r = 0;
	int res;
	for (i = n - 1; i >= 0; i--) {
		if (x[i] == '1') {
			res = pow(n - i - 1);
			q += res / -8;
			r += res % -8;
		}
	}
	res = r;
	r = res % -8;
	q += res / -8;
	if (r < 0) {
		r = 8 + r;
		q += 1;
	} 
	i = 10;
	while (q < 0 || q >= 8) {
		res = q;
		if (res <= -8 || res >= 8) {
			q = q / -8;
			res = res % -8;
		}
		if (res < 0 && res > -8) {
			if (q < 0 && q > -8) {
				q = 1;
			} else {
				q += 1;
			}
			res = 8 + res;
		} 
		r = (res * i) + r;
		i *= 10;
	}
	r = (q * i) + r;
	return r;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *x;
	int n;
	printf("Enter the  length of base -2 number: ");
	scanf("%d", &n);
	x = (char *) malloc(sizeof(char) * n);
	printf("Enter base -2 number: ");
	scanf("%s", x);
	printf("Base -8 number: %d", conversion(x, n));
	getch();
	return 0;
}

