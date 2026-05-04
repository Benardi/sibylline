#include <cdll.h>
#include <stdlib.h>

void cdll_init(CircularDoublyLinkedList* nil)
{
  nil->next = nil;
  nil->prev = nil;
}

CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil, Item item)
{
  CircularDoublyLinkedList* node;
  node = malloc(sizeof(CircularDoublyLinkedList));
  node->data = item;

  node->next = nil->next;
  nil->next->prev = node;
  nil->next = node;
  node->prev = nil;

  return node;
}

CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil, int key,
                                      int (*compare)(int, int))
{
  CircularDoublyLinkedList* node;

  node = nil->next;
  while (node != nil && compare(node->data.key, key) != 0)
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
