// sort2NumLL.cpp : Defines the entry point for the console application.
//

/* 7.Sorted a linked list which is in ascending order but two numbers are changed ,i mean not in the usual order they need to be
Ex: 1->2->3->15->10->4->20; O/p:1-2-3-4-10-15-20*/

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
	printf("Do u want to continue(y/n): ");
	scanf("%c", &c);
	while (c == 'y') {
		temp = (struct node *) malloc(sizeof(struct node));
		printf("Enter an element: ");
		scanf("%d", &(temp -> num));
		if (head == NULL) {
			head = temp;
			last = temp;
		} else {
			last -> next = temp;
			last = last -> next;
		}
		fflush(stdin);
		printf("Do u want to continue(y/n): ");
		scanf("%c", &c);
	}
	last -> next = NULL;
	return head;
}

void display(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d\t", temp -> num);
		temp =temp -> next;
	}
	printf("\n");
}

struct node * sort(struct node *head) {
	if (head == NULL)
		return head;
	struct node *temp = head;
	struct node *ptr;
	int n;
	while (temp -> next != NULL && temp -> num < temp -> next -> num) {
		temp = temp -> next;
	}
	if (temp -> next != NULL) {
		ptr = temp;
		temp = temp -> next;
	}
	if (temp -> next -> num < ptr -> num) {
		while (temp -> next != NULL && temp -> num < temp -> next -> num) {
			temp = temp -> next;
		}
		temp = temp -> next;
	}
	if (temp -> next != NULL) {
		n = ptr -> num;
		ptr -> num = temp -> num;
		temp -> num = n;
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Create LL: \n");
	struct node *head = create(NULL);
	display(head);
	head = sort(head);
	display(head);
	getch();
	return 0;
}

