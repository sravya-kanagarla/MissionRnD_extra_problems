// ascDescSort.cpp : Defines the entry point for the console application.
//

/* 8.Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
Note : min of descending part is greater than max of ascending 
Ex: Input 1->2->7->20->15->10
Output 1->2->7->10->15->20 */

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

struct node * reverse(struct node * head) {
	struct node *revHead;
	if (head == NULL || head -> next == NULL) {
		return head;
	}
	revHead = reverse(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return revHead;
}

struct node * sort(struct node *head) {
	struct node *temp = head;
	struct node *temp1;
	while (temp -> next != NULL && temp -> num < temp -> next -> num) {
		temp1 = temp;
		temp = temp -> next;
	}
	temp1 -> next = reverse(temp);
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

