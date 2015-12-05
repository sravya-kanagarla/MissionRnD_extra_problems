// addNodeCLL.cpp : Defines the entry point for the console application.
//

/* 3.Add a node to the circular linked list */

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
	printf("Do u want to continue: ");
	scanf("%c", &c);
	while (c == 'y') {
		temp = (struct node *) malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d", &(temp -> num));
		if (head == NULL) {
			head = temp;
			last = temp;
		} else {
			last -> next = temp;
			last = last -> next;
		}
		fflush(stdin);
		printf("Do u want to continue: ");
		scanf("%c", &c);
	}
	last -> next = head;
	return head;
}
void display(struct node *head) {
	struct node *temp = head;
	while (temp -> next != head) {
		printf("%d\t", temp -> num);
		temp = temp -> next;
	}
	printf("%d\n", temp -> num);
}

struct node * addNode(struct node *head, int n) {
	if (head == NULL)
		return head;
	struct node *temp = head;
	struct node *temp1;
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr -> num = n;
	while (temp -> next != head && temp -> num < n) {
		temp1 = temp;
		temp = temp -> next;
	}
	if (temp -> next == head) {
		temp -> next = ptr;
		ptr -> next = head;
	} else if (temp == head) {
		ptr -> next = head;
		while (temp -> next != head) {
			temp = temp -> next;
		}
		temp -> next = ptr;
		head = ptr;
	} else {
		temp1 -> next = ptr;
		ptr -> next = temp;
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("Create CLL: \n");
	struct node *head = create(NULL);
	printf("Enter number to be inserted: ");
	scanf("%d", &n);
	head = addNode(head, n);
	display(head);
	getch();
	return 0;
}

