// link.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct node {
	int data;
	node* next;
};
void PrintToCircularLinkedList(node* list) {
	node* iter = list;
	printf("%d ", iter->data);
	iter = iter->next;
	while (iter != list) {
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}
void InsertToEndForCircular(node* list, int value) {
	node* iter = list;
	while (iter->next != list) {
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = value;
	iter->next->next = list;
}
node* InsertToLinkedListForCircular(node* list, int value) {
	if (list == NULL) { // If list is empty.
		list = (node*)malloc(sizeof(node));
		list->next = list;
		list->data = value;
		return list;
	}
	if (list->data > value) { // Insert to left.
		node* temp = (node*)malloc(sizeof(node));
		temp->next = list;
		temp->data = value;
		node* iter = list;
		while (iter->next != list)
			iter = iter->next;
		iter->next = temp;
		return temp;
	}

	// Insert to between two values or to right.
	node* iter = list;
	while (iter->next != list && iter->next->data < value) {
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = value;
	return list;

}
node* DeleteFromListForCircular(node* list, int value) {
	node* iter = list;
	node* temp;
	if (list->data == value) { // If the value is first value
		while (iter->next != list) {
			iter = iter->next;
		}
		iter->next = list->next;
		free(list); // Delete from the memory.
		return iter->next;
	}
	while (iter->next != list && iter->next->data != value) {
		iter = iter->next;
	}
	if (iter->next == list) {
		printf("Value not found! -->");
		return list;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return list;
}
int main()
{
	node* root;
	root = NULL;

	root = InsertToLinkedListForCircular(root, 100);
	root = InsertToLinkedListForCircular(root, 1);
	root = InsertToLinkedListForCircular(root, 50);
	root = InsertToLinkedListForCircular(root, 23);
	root = InsertToLinkedListForCircular(root, 50);
	root = InsertToLinkedListForCircular(root, 150);
	root = InsertToLinkedListForCircular(root, 12);
	root = InsertToLinkedListForCircular(root, 11);
	root = InsertToLinkedListForCircular(root, 999);

	InsertToEndForCircular(root, 34);
	PrintToCircularLinkedList(root);

	root = DeleteFromListForCircular(root, 23);
	PrintToCircularLinkedList(root);

	root = DeleteFromListForCircular(root, 1);
	PrintToCircularLinkedList(root);

	root = DeleteFromListForCircular(root, 999);
	PrintToCircularLinkedList(root);

	root = DeleteFromListForCircular(root, 283);
	PrintToCircularLinkedList(root);

	return 0;
}