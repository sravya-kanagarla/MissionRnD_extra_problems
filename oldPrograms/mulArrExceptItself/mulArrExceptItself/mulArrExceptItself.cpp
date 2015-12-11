// mulArrExceptItself.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Multiplication of array elements such that multilication of all the array elements except the currnt index position */

int * multiply(int *a, int n) {
	int *b = (int *) malloc (n * sizeof(int));
	int i;
	b[n - 1] = a[n - 1];
	for (i = n - 2; i > 0; i--) 
		b[i] = a[i] * b[i + 1];
	for (i = 1; i < n - 1; i++)
		a[i] = a[i] * a[i - 1];
	b[0] = b[1];
	for (i = 1; i < n - 1; i++) 
		b[i] = a[i - 1] * b[i + 1];
	b[n - 1] = a[n - 2];
	return b;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int *a;
	int *b;
	int n;
	int i;
	printf("Enter the size: ");
	scanf("%d", &n);
	a = (int *) malloc (n * sizeof(int));
	printf("Enter the elements: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	b = multiply(a, n);
	for (i = 0; i < n; i++)
		printf("%d\t", b[i]);
	getch();
	return 0;
}