// reverseLLRecursion.cpp : Defines the entry point for the console application.
//

/* 4.Reverse an Linked list , using recursion  */

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * create(struct node *head) {
	struct node *temp;
	struct node *last;
	char c;
	fflush(stdin);
	printf("Do you want to continue(y/n): ");
	scanf("%c", &c);
	while (c == 'y') { 
		temp = (struct node *)malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d", &(temp -> num));
		if (head == NULL) {
			head = temp;
			last = head;
		} else {
			last -> next = temp;
			last = last -> next;
		}
		fflush(stdin);
		printf("Do you want to continue(y/n): ");
		scanf("%c", &c);
	}
	last -> next = NULL;
	return head;
}

void display(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d\t", temp -> num);
		temp = temp -> next;
	}
	printf("\n");
}

struct node * reverse1(struct node * head) {
	struct node *revHead;
	if (head == NULL || head -> next == NULL) {
		return head;
	}
	revHead = reverse1(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return revHead;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head = create(NULL);
	display(head);
	head = reverse1(head);
	display(head);
	getch();
	return 0;
}

