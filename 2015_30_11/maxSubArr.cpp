// maxSubArr.cpp : Defines the entry point for the console application.
//

/* 9 . Largest Contiguous Sum Array .
Ex : 1,2,3,5,-10,20,40 O/P : 20,40 Sum : 60*/

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int findSum(int *a, int len) {
	int i;
	int j = len - 1;
	int sum = 0;
	int lastSum = 0;
	for (i = 0; i < len; i++) {
		if (a[i] < 0) {
			for (j = len - 1; j >= i; j--) {
				lastSum += a[j];
				if (lastSum <= 0) {
					if ((i != j) && ((sum + a[i]) > 0))
						sum += a[i];
					lastSum = 0;
					break;
				}
				if (lastSum > sum) {
					sum = 0;
				}
			}
		} else {
			sum += a[i];
		}
		if (i == j)
			break;
		printf("%d\n", sum);
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len;
	int *a;
	int i;
	printf("Enter length: ");
	scanf("%d", &len);
	printf("Enter elements: \n");
	a = (int *) malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		scanf("%d", &a[i]);
	printf("\n");
	printf("Sum: %d", findSum(a, len));
	getch();
	return 0;
}

