#include <cdll.h>
#include <malloc.h>

void cdll_init(CircularDoublyLinkedList* nil)
{
  nil->next = nil;
  nil->prev = nil;
}

CircularDoublyLinkedList* cdll_insert(CircularDoublyLinkedList* nil,
                                      Register reg)
{
  CircularDoublyLinkedList* node;
  node = malloc(sizeof(CircularDoublyLinkedList));
  node->data = reg;

  node->next = nil->next;
  nil->next->prev = node;
  nil->next = node;
  node->prev = nil;

  return node;
}

CircularDoublyLinkedList* cdll_search(CircularDoublyLinkedList* nil,
                                      union Key key,
                                      int (*compare)(union Key, union Key))
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
