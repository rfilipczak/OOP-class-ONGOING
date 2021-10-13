#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "./circular_list.h"


Node *list_new_node(int val)
{
	Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL)
    {
        perror("Allocation failed when allocating node");
        abort();
    }
	node->prev = NULL;
	node->prev = NULL;
	node->key = val;
	return node;
}

int list_is_empty(const CircularList *list)
{
    assert(list != NULL);
	return (list->head == NULL && list->tail == NULL);
}

// Adds node into EMPTY list.
static void list_empty_add_node(CircularList *list, Node *node)
{
    assert(list != NULL);
    assert(node != NULL);
    assert(list_is_empty(list));

    node->prev = node;
    node->next = node;
    list->head = node;
    list->tail = node;
}

// Adds node into the "end" of NON-EMPTY list without changing list's head nor tail.
// Caller should then set head or tail to node. 
// Reasoning: avoids repetition of code in list_push_back and list_push_front.
static void list_add_node(CircularList *list, Node *node)
{
    assert(list != NULL);
    assert(node != NULL);
    assert(!list_is_empty(list));

    node->prev = list->tail;
    node->next = list->head;
    list->tail->next = node;
    list->head->prev = node;
}

Node *list_push_back(CircularList *list, int val)
{
    assert(list != NULL);

	Node *node = list_new_node(val);

	if (list_is_empty(list))
    {
        list_empty_add_node(list, node);
    } 
    else
    {
        list_add_node(list, node);
        list->tail = node;
	}
	return node;
}

CircularList *list_create(const Array *values)
{
    assert(values != NULL && "values must be a valid pointer");
    assert(values->size > 0 && "array size must be > 0");
    assert(values->data != NULL && "array data must be a valid pointer");

    CircularList *list = (CircularList *) malloc(sizeof(CircularList));
    if (list == NULL)
    {
        perror("Allocation failed when allocating list");
        abort();
    }
    list->head = NULL;
    list->tail = NULL;
    for (int i = 0; i < values->size; ++i)
        list_push_back(list, values->data[i]);
    return list;
}

void list_clear(CircularList *list)
{
    assert(list != NULL && "list should be a valid pointer");
    if (list_is_empty(list))
        return;

    // one node in list
    if (list->head == list->tail)
    {
        free(list->head);
    }
    else
    {
        Node *node = list->head;
        Node *next = NULL;
        do {
            next = node->next;
            free(node);
            node = next;
        } while (node != list->head);
    }
    
    list->head = NULL;
    list->tail = NULL;
}

void list_destroy(CircularList *list)
{
    assert(list != NULL && "list should be a valid pointer");
    list_clear(list);
    free(list);
}

void list_print(const CircularList *list)
{
    assert(list != NULL && "list should be a valid pointer");
    if (list_is_empty(list))
    {
        printf("Nothing to show.\n");
    }
    else
    {
        const Node *node = list->head;
        do {
            printf("%d ", node->key);
            node = node->next;
        } while (node != list->head);
        printf("\n");
    }
}

Node *list_push_front(CircularList *list, int val)
{
    assert(list != NULL);

   	Node *node = list_new_node(val);
    
    if (list_is_empty(list))
    {
        list_empty_add_node(list, node);
    }
    else
    {
        list_add_node(list, node);
        list->head = node;
    }
    return node;
}

int list_delete(CircularList *list, int val)
{
    assert(list != NULL && "list should be a valid pointer");
    
    if (list_is_empty(list))
        return 0;

    // just one node in the list
    if (list->head == list->tail)
    {
        if (list->head->key == val)
        {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            return 1; // TODO: too many returns?
        }
        else
        {
            return 0; // TODO: too many returns?
        }
    }
    else
    {
        // more nodes

        Node *node = list->head;
        Node *next;

        do {
            next = node->next;
            if (node->key == val)
            {
                if (node == list->head)
                {
                    list_pop_front(list);
                }
                else if (node == list->tail)
                {
                    list_pop_back(list);
                }
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    free(node);
                }
                return 1; // TODO: too many returns?
            }
            node = next;
        } while (node != list->head);
    }

    // no node with key==val found
    return 0;
}

void list_delete_all(CircularList *list, int val)
{
    // this could be written better with just one iteration over the list
    // but then again it wouldn't be as simple as this
    int result;
    do {
        result = list_delete(list, val);
    } while (result);
}

int list_pop_back(CircularList *list)
{
    if (list_is_empty(list))
        return 0;
    Node *node = list->tail;
    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head->prev = node->prev;
        node->prev->next = list->head;
        list->tail = node->prev;
    }
    free(node);
    return 1;
}

int list_pop_front(CircularList *list)
{
    if (list_is_empty(list))
        return 0;
    Node *node = list->head;
    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node->next->prev = list->tail;
        list->tail->next = node->next;
        list->head = node->next;
    }
    free(node);
    return 1;
}

void list_print_reversed(const CircularList *list)
{
    assert(list != NULL && "list should be a valid pointer");
    if (list_is_empty(list))
    {
        printf("Nothing to show.\n");
    }
    else
    {
        const Node *node = list->tail;
        do {
            printf("%d ", node->key);
            node = node->prev;
        } while (node != list->tail);
        printf("\n");
    }
}
