// rthNumInSeq.cpp : Defines the entry point for the console application.
//

/* 5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
Ex , n1=3 ,n2=5 and r=5, The merged table is 3,5,9,10,12,15(One more 15 is removed as its duplicate ) 18,20,21,24,25........so on .
The rth num ie 5th number is 12 ,so OP is 12
*/

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int findElement(int n1, int n2, int r) {
	int i = n1;
	int j = n2;
	while (r > 1) {
		if (n1 < n2) {
			n1 += i;
		} else if (n1 > n2) {
			n2 += j;
		} else {
			n1 += i;
			n2 += j;
		}
		r--;
	}
	if (n1 < n2)
		return n1;
	return n2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n1;
	int n2;
	int r;
	printf("Enter two numbers: \n");
	scanf("%d%d", &n1, &n2);
	printf("Enter r: ");
	scanf("%d", &r);
	printf("%d element is %d", r, findElement(n1, n2, r));
	getch();
	return 0;
}

