// dateprint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int strLen(char *a) {
	int i;
	for (i = 0; a[i] != '\0'; i++);
	return i;
}

int validate(int day, int mon, int year) {
	int i;
	for (i = 0; year > 0; i++) 
		year /= 10;
	if (i != 4)
		return 1;
	if (mon < 1 || mon > 12) {
		return 1;
	} else {
		if (mon == 2) {
			if (!(((year % 4) && !(year % 100)) || (year % 400)))  {
				if (day < 1 || day > 29) {
					return 1;
				} else if (day < 1 || day > 28) {
					return 1;
				}
			}
		} else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
			if (day < 1 || day > 30) {
					return 1;
				}
		} else {
			if (day < 1 || day > 31) {
				return 1;
			}
		}
	}
	return 0;
}

char * calcDate(char date[]) {
	char onesWithTH[][10] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};
	char ones[][7] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char months[][10] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
	char tens[][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char teens[][8] = {"ten", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety"};
	char *spell;
	int i;
	int day = 0;
	int mon = 0;
	int year = 0;
	for (i = 0; date[i] != '/' && date[i] != '\0'; i++)  {
		day = day * 10 + (date[i] - '0');
	}
	i++;
	while (date[i] != '/' && date[i] != '\0') { 
 		mon = mon * 10 + (date[i] - '0');
		i++;
	}
	i++;
	while (date[i] != '\0') {
		year = (year * 10) + (date[i] - '0');
		i++;
	}
	if (validate(day, mon, year)) {
		spell = (char *) malloc(sizeof(15));
		spell = "Invalid Input";
	} else {
		if (day / 10 == 1) {
			spell = (char *) malloc(sizeof(tens[day % 10]) + 3);
			sprintf(spell, "%sth ", tens[day % 10]);
		} else if (day / 10 == 2) {
			spell = (char *) malloc(sizeof(onesWithTH[day % 10 - 1]) + 8);
			sprintf(spell, "%s %s ", teens[1], onesWithTH[day % 10 - 1]);
		} else {
			spell = (char *) malloc(sizeof(onesWithTH[day - 1]) + 1);
			sprintf(spell, "%s ", onesWithTH[day - 1]);
		}
		spell[strLen(spell)] = '\0';
		spell = (char *) realloc(spell, strLen(spell) + sizeof(months[mon - 1]) + 4);
		sprintf(&spell[strLen(spell)], "%s of ", months[mon - 1]);
		spell[strLen(spell)] = '\0';
		if ((year / 1000) == 1) {
			if ((year / 100) % 10) {
				spell = (char *) realloc(spell, strLen(spell) + sizeof(tens[(year /100) % 10]));
				sprintf(&spell[strLen(spell)], "%s ", tens[(year /100) % 10]);
			}
		} else {
			if ((year / 100) % 10) {
				spell = (char *) realloc(spell, strLen(spell) + sizeof(teens[year / 1000 - 1]) + sizeof(ones[((year / 100) % 10) - 1]));
				sprintf(&spell[strLen(spell)], "%s %s ", teens[year / 1000 - 1], ones[((year / 100) % 10) - 1]);
			} else {
				spell = (char *) realloc(spell, strLen(spell) + 10 + sizeof(ones[year / 1000 - 1]));
				sprintf(&spell[strLen(spell)], "%s thousand ", ones[year / 1000 - 1]);
			}
		}
		spell[strLen(spell)] = '\0';
		if (!((year / 10) % 10)) {
			if ((year / 100) % 10) {
				spell = (char *) realloc(spell, strLen(spell) + sizeof(ones[year % 10 - 1]));
				sprintf(&spell[strLen(spell)], "hundred %s", ones[year % 10 - 1]);
			} else {
				spell = (char *) realloc(spell, strLen(spell) + sizeof(ones[year % 10 - 1]));
				sprintf(&spell[strLen(spell)], "%s", ones[year % 10 - 1]);
			}
		} else if (((year / 10) % 10) == 1) {
			spell = (char *) realloc(spell, strLen(spell) + sizeof(tens[year % 10]));
			sprintf(&spell[strLen(spell)], "%s", tens[year % 10]);
		} else if (!(year % 10)) {
			spell = (char *) realloc(spell, strLen(spell) + sizeof(teens[(year / 10) % 10 - 1]));
			sprintf(&spell[strLen(spell)], "%s", teens[(year / 10) % 10 - 1]);
		} else {
			spell = (char *) realloc(spell, strLen(spell) + sizeof (teens[((year / 10) % 10) - 1]) + sizeof (ones[year % 10 - 1]));
			sprintf(&spell[strLen(spell)], "%s %s", teens[((year /10) % 10) - 1], ones[year % 10 - 1]);
		}
	}
	return spell;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char date[11];
	printf("Enter the date: ");
	scanf("%s", date);
	printf("%s", calcDate(date));
	getch();
	return 0;
}