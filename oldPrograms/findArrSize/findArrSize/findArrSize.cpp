// findArrSize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int arrSize(int *a) {
	int n = 1;
	while(a[n] < a[n + 1]) {
		n *= 2;
	}
	if (a[n] == 0) {
		int m = n / 2;
		while (a[n] == 0 || a[n] < a[n + 1]) {
			if (a[n] == 0) {
				n = (m + n) / 2;
				/*n = (i * n) / (1 + i);
				i *= 2;
				n = n + n / i;*/
			} else {
				m = 2 * n - m;
				n = (m + n) / 2;
				m = 2 * n - m;
			}
		}
	}
	if (a[n] > a[n + 1] && a[n] < a[n - 1])
			n--;
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int *a;
	int n;
	int i;
	printf("Enter size of an array: ");
	scanf("%d", &n);
	a = (int *) malloc(sizeof(int) * n);
	printf("Enter array elements: \n");
	for (i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	printf("Size of the array: %d", arrSize(a));
	getch();
	return 0;
}