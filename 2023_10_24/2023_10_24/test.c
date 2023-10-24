#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* InitList() {
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}


void HeadInsert(Node* list, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;
}

void TailInsert(Node* list, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* head = list;
	list = list->next;
	while (list->next) {
		list = list->next;
	}
	list->next = node;
	head->data++;
}

void DelList(Node* list, int data) {
	Node* pre = list;
	Node* cur = list->next;
	while (cur) {
		if (cur->data == data) {
			pre->next = cur->next;
			free(cur);
			break;
		}
		pre = cur;
		cur = cur->next;
		
	}
	list->data--;
}

void PrintList(Node* list) {
	list = list->next;
	while (list) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int main() {
	Node* list = InitList();
	HeadInsert(list, 1);
	HeadInsert(list, 2);
	HeadInsert(list, 3);
	HeadInsert(list, 4);
	HeadInsert(list, 5);
	TailInsert(list, 6);
	TailInsert(list, 7);
	TailInsert(list, 8);
	TailInsert(list, 9);
	TailInsert(list, 10);
	DelList(list, 5);
	DelList(list, 10);
	DelList(list, 6);
	PrintList(list);

	return 0;
}