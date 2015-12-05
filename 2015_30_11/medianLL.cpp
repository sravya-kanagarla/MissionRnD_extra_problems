// medianLL.cpp : Defines the entry point for the console application.
//

/*1.Find median of a given linked list (Sorted Linked List)*/

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
	do { 
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
	}while(c == 'y');
	last -> next = NULL;
	return head;
}

int findMedian(struct node *head) {
	if (head -> next == NULL) {
		return head -> num;
	}
	struct node *ptr = head -> next;
	while (ptr -> next != NULL) {
		head = head -> next;
		ptr = ptr -> next;
		if (ptr -> next == NULL)
			return head -> num;
		ptr = ptr -> next;
	}
	return ((head -> num) + (head -> next -> num)) / 2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head = create(NULL);
	printf("Median: %d\n", findMedian(head));
	getch();
	return 0;
}

