#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

//
// CIRCULAR DOUBLY LINKED LIST 
//

#include "./array.h"

typedef struct Node {
	struct Node *prev;
	struct Node *next;
	int key;
} Node;

typedef struct CircularList {
	Node *head;
	Node *tail;
} CircularList;

// Returns allocated node with value val.
// Warning: will abort the program on allocation failure.
Node *list_new_node(int val);

// Creates a new list from array of integers.
// Warning: will abort the program on allocation failure.
CircularList *list_create(const Array *values);

// Returns 1 if list is empty, 0 otherwise.
int list_is_empty(const CircularList *list);

// Pushes a new node with value val at the back of the list.
// Returns pushed node.
// Warning: will abort the program on allocation failure.
Node *list_push_back(CircularList *list, int val);

// Pushes a new node with value val at the front of the list.
// Returns pushed node.
// Warning: will abort the program on allocation failure.
Node *list_push_front(CircularList *list, int val);

// Deletes first node with value val in the list. Searches from the beginning of the list.
// Returns 1 if there was a node, 0 otherwise.
int list_delete(CircularList *list, int val);

// Deletes all nodes with value val.
void list_delete_all(CircularList *list, int val);

// Deletes first node from the list.
// Returns 1 if there was a node, 0 otherwise.
int list_pop_back(CircularList *list);

// Deletes last node from the list.
// Returns 1 if there was a node, 0 otherwise.
int list_pop_front(CircularList *list);

// Frees all the nodes of the list. Sets head and tail to NULL.
void list_clear(CircularList *list);

// Frees all the nodes of the list and then frees the list.
void list_destroy(CircularList *list);

// Prints values of the list or "Nothing to show" if the list is empty.
void list_print(const CircularList *list);

// Prints values of the list in the reversed order or "Nothing to show" if the list is empty.
void list_print_reversed(const CircularList *list);


#endif // CIRCULAR_LIST_H
