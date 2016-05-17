#ifndef LIST_H
#define LIST_H

typedef struct node {
	/* Internal linked list information */
	struct node *next; // Pointer to next node in the list
	struct node *prev; // Pointer to previous node in the list
	int value; // Data value stored in the node
} DLLItem;

typedef struct linkedlist {
	struct node *head;
	struct node *tail;
} DLList;

DLList * create_linkedlist();

void llist_add(DLList * list, int value);

void llist_remove(DLList * list, int value);

int llist_insertAfter_ith(DLList * list, int ith, int value);

int llist_remove_ith(DLList * list, int ith);

int llist_remove_first(DLList * list);

int llist_remove_last(DLList * list);

void llist_insert_first(DLList * list, int value);

void llist_insert_last(DLList * list, int value);

DLList *llist_intersection(DLList * list1, DLList * list2);

DLList * llist_union(DLList *list1, DLList * list2);

void llist_sort(DLList * list, int ascending);

void llist_removeRange(DLList * list, int low, int high);

#endif

