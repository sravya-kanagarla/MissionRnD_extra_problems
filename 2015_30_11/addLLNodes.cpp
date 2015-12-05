// addLLNodes.cpp : Defines the entry point for the console application.
//

/* 6.Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
Ex: Input 1->2->3->4 and 1->2->3->4
Output 2->4->6->8 */

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node * next;
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
		temp -> next = NULL;
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

struct node * add(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	while (temp1 -> next != NULL && temp2 != NULL) {
		temp1 -> num = temp1 -> num + temp2 -> num;
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
	if (temp1 -> next == NULL && temp2 != NULL)
		temp1 -> num = temp1 -> num + temp2 -> num;
	if (temp2 != NULL) {
		temp1 -> next = temp2 -> next;
	}
	return head1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Enter first LL elements: \n");
	struct node *head1 = create(NULL);
	printf("Enter second LL elements: \n");
	struct node *head2 = create(NULL);
	head1 = add(head1, head2);
	display(head1);
	getch();
	return 0;
}

