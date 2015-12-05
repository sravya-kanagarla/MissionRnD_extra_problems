// merge2LL.cpp : Defines the entry point for the console application.
//
/* 2.Merge two linked list which are in sorted order */

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
}

struct node * merge(struct node *head1, struct node *head2) {
	struct node * head = NULL;
	struct node * last = head;
	struct node *temp;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	while (head1 != NULL && head2 != NULL) {
		if (head1 -> num < head2 -> num) {
			temp = head1;
			head1 = head1 -> next;
		} else {
			temp = head2;
			head2 = head2 -> next;
		}
		temp -> next = NULL;
		if (head == NULL) {
			head = temp;
			last = temp;
		} else {
			last -> next = temp;
			last = last -> next;
		}
	}
	if (head1 == NULL && head2 != NULL) {
		last -> next = head2;
	} else {
		last -> next = head1;
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Enter first linked list elements: \n");
	struct node *head1 = create(NULL);
	printf("Enter second linked list elements: \n");
	struct node *head2 = create(NULL);
	head1 = merge(head1, head2);
	display(head1);
	getch();
	return 0;
}

