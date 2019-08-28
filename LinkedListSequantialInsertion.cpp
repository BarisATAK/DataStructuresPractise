// link.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct node {
	int data;
	node* next;
};
void PrintToLinkedList(node* list) {
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}
void InsertToEnd(node* list, int value) {
	while (list->next != NULL) {
		list = list->next;
	}
	list->next = (node*)malloc(sizeof(node));
	list->next->data = value;
	list->next->next = NULL;
}
node* DeleteFromList(node* list, int value) {
	node* temp; // To make free.
	node* iter = list;
	if (list->data == value) { // If the value is first value.
		temp = list;
		list = list->next;
		free(temp);
		return list;
	}
	while (iter->next != NULL && iter->next->data != value) {
		iter = iter->next;
	}
	if (iter->next == NULL) {
		printf("Value not found-->");
		return list;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp); // Delete from the memory.
	return list;
}
node* InsertToLinkedList(node* list, int value) {
	if (list == NULL) { // If list is empty.
		node* temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->data = value;
		list = temp;
		return list;
	}
	if (list->data > value) { // Insert to left.
		node* temp = (node*)malloc(sizeof(node));
		temp->next = list;
		temp->data = value;
		list = temp;
		return list;
	}

	// Insert to between two values or to right.
	node* iter = list;
	while (iter->next != NULL && iter->next->data < value) {
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = value;
	return list;

}
int main()
{
	node* root;
	root = NULL;

	root = InsertToLinkedList(root, 100);
	root = InsertToLinkedList(root, 1);
	root = InsertToLinkedList(root, 50);
	root = InsertToLinkedList(root, 23);
	root = InsertToLinkedList(root, 50);
	root = InsertToLinkedList(root, 150);
	root = InsertToLinkedList(root, 12);
	root = InsertToLinkedList(root, 11);
	root = InsertToLinkedList(root, 999);

	InsertToEnd(root, 34);

	PrintToLinkedList(root);

	root = DeleteFromList(root, 23);
	PrintToLinkedList(root);

	root = DeleteFromList(root, 1);
	PrintToLinkedList(root);

	root = DeleteFromList(root, 999);
	PrintToLinkedList(root);

	root = DeleteFromList(root, 283);
	PrintToLinkedList(root);

	return 0;
}