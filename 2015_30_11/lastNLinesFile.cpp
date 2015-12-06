// lastNLinesFile.cpp : Defines the entry point for the console application.
//

/* 10. Print the last n lines of a file */

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int getPtr(FILE *file, int k) {
	int line = 0;
	char c = fgetc(file);
	int *p = (int *) malloc(sizeof(int) * k);
	p[line % k] =  ftell(file);
	while ((c = fgetc(file)) != EOF) {
		if (c == '\n') {
			c = fgetc(file);
			p[line % k] =  ftell(file);
			line++;
		}
	}
	return p[line % k] -= 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k;
	FILE *file;
	int ptr;
	char c;
	printf("Enter no.of lines: ");
	scanf("%d", &k);
	file = fopen("sample.txt", "r");
	if (file == NULL) {
		printf("Error");
		exit(1);
	}
	ptr = getPtr(file, k); 
	fseek(file, ptr, SEEK_SET);
	while ((c = fgetc(file)) != EOF) {
		printf("%c", c);
	}
	fclose(file);
	getch();
	return 0;
}

