#include <malloc.h>
#include <cdll.h>

void cdll_init(CircularDoublyLinkedList* nil)
{
    nil->next = nil;
    nil->prev = nil;    
}

CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil, Key k)
{
    CircularDoublyLinkedList* node;
    node = malloc(sizeof(CircularDoublyLinkedList));
    node->data.key = k;
     
    node->next = nil->next;
    nil->next->prev = node;
    nil->next = node;
    node->prev = nil;

    return node;
}

CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil, Key k)
{
    CircularDoublyLinkedList* node;

    node = nil->next;
    while ((node != nil) && (node->data.key != k))
    {
        node = node->next;
    }
    return node;
}

void cdll_delete(CircularDoublyLinkedList* to_remove)
{
    (to_remove->prev)->next = to_remove->next;
    (to_remove->next)->prev = to_remove->prev;
}