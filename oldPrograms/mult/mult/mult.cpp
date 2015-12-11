// mult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int logic1(int x, int y) {
	int ans = 0;
	int flag = 0;
	if (y < 0) {
		y = -y;
		flag = 1;
	}
	while (y > 0) {
		if (y & 1)
			ans += x;
		y >>= 1;
		x <<= 1;
	}
	if (flag) 
		return -ans;
	return ans;
}

int add(int x, int y) {
	int carry = 0;
	while (y != 0) {
		carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}

int noOfDigits(int y) {
	int count = 0;
	while (y > 0) {
		count++;
		y >>= 1;
	}
	return count;
}

int logic2(int x, int y) {
	int flag = 0;
	if (y < 0) {
		y = -y;
		flag = 1;
	}
	int count = noOfDigits(y);
	x <<= count;
	while (count > 0){
		if (y & 1) {
			y = add(x, y);
		}
		y >>= 1;
		count--;
	}
	if (flag)
		return -y;
	return y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	int y;
	printf("Enter two integers: \n");
	scanf("%d%d", &x, &y);
	printf("Logic 1: %d\n", logic1(x, y));
	printf("Logic 2: %d\n", logic2(x, y));
	getch();
	return 0;
}