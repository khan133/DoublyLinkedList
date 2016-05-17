#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*DLList * create_linkedlist() {
	DLList *linkedlist_t = (DLList *) malloc(sizeof(DLList));
	linkedlist_t -> tail = NULL;
	linkedlist_t -> head = NULL;
	return linkedlist_t; 
}*/
void printer(DLList * list) {
	//	prints linked list
	printf("******\n");
	DLLItem* temp = list -> head;
	while (temp != NULL) {
		printf("%d\n", temp -> value);
		temp = temp -> next;
	}
	printf("********\n");                                                       }
	void llist_add(DLList * list, int value) {
		DLLItem* item = (DLLItem*) malloc(sizeof(DLLItem));
		item -> value = value; 
		if (list -> tail == NULL) {
			list -> head = item;
			list -> tail = item;
			item -> prev = NULL;
			item -> next = NULL;
		}
		else {
			DLLItem* temp = list -> tail; 
			temp -> next = item; 
			item -> prev = temp;
			list -> tail = item;
			item -> next = NULL; 
		}
	}
void llist_remove(DLList * list, int value) {
	DLLItem* temp = list -> head;
	while (temp != NULL) {
		if (list -> head == list -> tail&& temp -> value == value) {
			list -> head = NULL;
			list -> tail = NULL; 
			break; 
		}
		else if (temp == list -> tail && temp -> value == value) {
			DLLItem* temp2 = list -> tail -> prev; 
			list -> tail = temp2; 
			temp2 -> next = NULL; 
			free(temp); 
			temp = NULL;
			break; 	
		}
		else if (temp == list -> head && temp -> value == value) {
			DLLItem* temp2 = list -> head -> next;
			list -> head = temp2; 
			temp2 -> prev = NULL; 
			temp -> next = NULL;
			free(temp); 
			temp = NULL; 
			break; 
		}
		else if (temp -> value == value) {
			DLLItem* next = temp -> next;
			DLLItem* prev = temp -> prev; 
			prev -> next = next;
			next -> prev = prev; 
			free(temp);
			temp = NULL; 
			break; 
		}
		temp = temp -> next; 
	}

int llist_insertAfter_ith(DLList * list, int ith, int value) {
	int count = 0; 
	DLLItem* item = (DLLItem*) malloc(sizeof(DLLItem)); 
	item -> value = value; 
	DLLItem* temp = list -> head;
	//finds size of linked list
	while (temp != NULL) {
		count++; 
		temp = temp -> next;
	}
	//checks if ith is not an appropriate value; 
	if (count <= ith || ith < 0 ) {
		return 0; 
	}
	temp = list -> head; 
	int i; 
	//traverse through the loop 
	for (i = 0; i < ith; i++) {
		temp = temp -> next;
	} 
	//if adding to the end
	if (list-> tail == temp) { 
		temp -> next = item;
		item -> next = NULL;
		item -> prev = temp;
		list -> tail = item;
		return 1;
	}
	//adding to anything else
	else {
		temp -> next -> prev = item; 
		item -> next = temp -> next;
		item -> prev = temp;
		temp -> next = item;
	}
	return 1; 

}
int llist_remove_ith(DLList * list, int ith) {
	int count = 0; 
	DLLItem * temp = list -> head; 
	//find size of linked list
	while (temp != NULL) {
		count++; 
		temp = temp -> next; 
	}
	if (count <= ith || ith < 0)
		return 0;
	//traverse through the loop
	temp = list -> head; 
	int i; 
	for (i = 0; i < ith; i++) {
		temp = temp -> next; 
	}
	//if removing first element
	if (ith == 0) {
		list -> head = temp -> next;  
		free(temp);
		temp = NULL;

	}
	//if removing last element
	else if (ith == count-1) {
		list -> tail = temp -> prev; 
		temp -> prev -> next = NULL; 
		free(temp);
		temp = NULL; 
	}
	//removing any other element
	else {
		temp -> prev -> next = temp -> next; 
		temp -> next -> prev = temp -> prev; 
	}
	return 1; 

}
int llist_remove_first(DLList * list) {
	//checks if list is empty
	if (list -> head == NULL)
		return 0;
	//checks if there is only one element in linked list
	if (list -> head == list -> tail) {
		list -> head = NULL;
		list -> tail = NULL; 
	}
	//removes if there are multiple elements in linked list
	else {
		DLLItem* temp = list -> head; 
		list -> head = temp -> next; 
		free(temp); 
		temp = NULL; 
	}
	return 1; 
}
int llist_remove_last(DLList * list) {
	//do not remove if list is empty
	if (list -> head == NULL)
		return 0;
	//removing if theres one element in the list
	DLLItem* temp = list -> tail; 
	if (list -> head == list -> tail) {
		list -> tail = NULL; 
		list -> head = NULL;
		free(temp);
		temp = NULL; 
		return 1; 
	}
	//removing any other time

	temp -> prev -> next = NULL;
	list -> tail = temp -> prev; 
	free(temp);
	temp = NULL; 
	return 1; 
}
void llist_insert_first(DLList* list, int value) {
	//allocating space for a new item and setting its value to the parameter value
	DLLItem* new = (DLLItem*) malloc(sizeof(DLLItem)); 
	new -> value = value; 
	//checks if list is empty 
	if (list -> head == NULL) {
		list -> head = new; 
		list -> tail = new;
		return;	
	}
	//adds for any other situation
	DLLItem* head = list -> head; 
	new -> next = head; 
	head -> prev = new; 
	new -> prev = NULL; 
	list -> head = new; 	
}
void llist_insert_last(DLList * list, int value) {
	//allocates memory
	DLLItem* new = (DLLItem*) malloc(sizeof(DLLItem)); 
	DLLItem* temp = list -> tail; 
	new -> value = value;
	//checks if list is empty	
	if (list -> head == NULL) {
		list -> head = new;
		list -> tail = new;
		return; 	
	}
	temp -> next = new; 
	new -> prev = temp; 
	list -> tail = new; 
	new -> next = NULL;  
}
//contains is used in union and intersection to check if the third list contains the element. if the element is already in list3, dont add it. Otherwise, add
int contains(DLList * list, int value) {
	DLLItem* node = list -> head; 
	while (node != NULL) {
		if (node -> value == value)
			return 1;
		node = node -> next;
	}
	return 0; 
}
DLList *llist_insersection(DLList * list1, DLList * list2) {
	//creates 3rd linkedlist
	DLList * list3 = create_linkedlist(); 
	//checks for invalid parameters
	if (list1 == NULL || list2 == NULL)
		return NULL; 
	//traverse through the loops to find a match
	DLLItem* temp = list1 -> head; 
	DLLItem* temp2 = list2 -> head; 
	while (temp != NULL) {
		while(temp2 != NULL) {
			//if theres a match and list3 does not contain the value, add the value
			if (temp-> value == temp2-> value && !contains(list3, temp -> value))					llist_add(list3, temp -> value); 
			temp2 = temp2 -> next;
		}
		temp2 = list2 -> head;
		temp = temp -> next; 
	}
	//prints the last
	printer(list3); 
	return list3;
}
DLList *llist_union(DLList *list1, DLList *list2) {
	DLLItem* temp1 = list1 -> head;
	DLLItem* temp2 = list2 -> head;
	DLList* list3 = create_linkedlist(); 
	while (temp1 != NULL) {
		while (temp2 != NULL) {
			if (!contains(list3,temp2 -> value))
				llist_add(list3, temp2 -> value); 
			temp2 = temp2 -> next; 
		}
		if (!contains(list3, temp1 -> value))
			llist_add(list3, temp1 -> value);
		temp2 = list2 -> head;
		temp1 = temp1 -> next; 
	}
	printer(list3);
	return list3; 
}
void llist_sort(DLList * list, int ascending) {
	DLLItem * temp = list -> head; 
	//finds the size of the list
	int count = 0; 
	while (temp != NULL) {
		count++;
		temp = temp -> next;
	}
	temp = list -> head; 
	//bubble sort
	int curr = 0;
	while (curr <= count) {
		while (temp -> next != NULL) {
			if (ascending == 1) {
				DLLItem * next = temp -> next;
				if (temp -> value > next -> value) {
					int item = temp -> value;
					temp -> value = next -> value;
					next -> value = item; 
				}
			}
			if (ascending == 0) {
				DLLItem * next = temp -> next;
				if (temp -> value < next -> value) {
					int item = temp -> value; 
					temp -> value = next -> value;
					next -> value = item; 
				}
			}	
			temp = temp -> next; 
		}
		curr++; 
	}
}
void llist_removeRange(DLList * list, int low, int high) {
	DLLItem* temp = list -> head;
	while (temp != NULL) {
		//checks if the node's value is less than high and greater than low and then removes it
		if (temp -> value >= low && temp -> value <= high) {
			llist_remove(list, temp->value); 
		}
		temp = temp -> next; 
	}
}
int main() {
	/*DLList *list = create_linkedlist(); 
	llist_add(list, 2); 
	llist_remove(list, 2);
	llist_add(list, 0);
	llist_add(list, 7); 
	llist_remove(list,7);
	llist_remove(list, 16); 	
	llist_insertAfter_ith(list,0,1); 
	llist_add(list, 2); 
	llist_insertAfter_ith(list,2,3); 
	llist_remove_ith(list, 0); 
	llist_remove_ith(list, 7); 
	llist_remove_ith(list, 2); 
	llist_remove_first(list); 
	llist_remove_first(list); 
	llist_remove_last(list);
	llist_add(list, 19);
	llist_add(list, 14); 
	llist_remove_last(list); 
	llist_insert_first(list, 6); 
	llist_insert_last(list, 9); 
	DLList *list1 = create_linkedlist(); 
	llist_add(list1,1);
	llist_add(list1,2);
	llist_add(list1,3);
	llist_add(list1,4);
	DLList * list2 = create_linkedlist();
	llist_add(list2, 3); 
	llist_add(list2,4);
	llist_add(list2, 7); 
	llist_union(list1, list2); 
	llist_sort(list, 1);
//	llist_add(list4, 1);
//	llist_add(list4, 7); 
//	llist_add(list4, 9); 
//	llist_add(list4, 8); 
//	llist_add(list4, 8); 
//	llist_add(list4,1); 
//	llist_add(list4, 5); 
//	llist_removeRange(list4, 3, 8); 
//	printer(list4); */	
	return 0; 
}
