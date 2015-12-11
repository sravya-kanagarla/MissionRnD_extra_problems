//sort_0_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Sort 0's and 1's such that 1's are followed by 0's */

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void sort(int *a, int n) {
	int i = 0;
	while (i < n) {
		if(a[i] == 1) {
			while (a[n] != 0 && i < n) 
				n--;
			if (a[n] == 0) 
				swap(&a[i], &a[n]);
		} else if (a[n] == 0) {
			while (a[i] != 1 && n > i) 
				i++;
			if (a[i] == 1) 
				swap(&a[i], &a[n]);
		}
		i++;
		n--;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int *a;
	int n;
	int i;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	a = (int *) malloc(sizeof(int) * n);
	printf("Enter the elements: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, n);
	for (i = 0; i < n; i++) 
		printf("%d\t", a[i]);
	getch();
	return 0;
}
