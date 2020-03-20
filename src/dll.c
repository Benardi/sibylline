#include <dll.h>
#include <malloc.h>

DoublyLinkedList* dll_insert(DoublyLinkedList** head, Register reg)
{
  DoublyLinkedList* node;
  node = malloc(sizeof(DoublyLinkedList));
  node->data = reg;
  node->next = *head;
  node->prev = NULL;

  if (*head != NULL)
    {
      (*head)->prev = node;
    }
  *head = node;
  return node;
}

DoublyLinkedList* dll_search(DoublyLinkedList** head, Key k)
{
  DoublyLinkedList* node;

  node = (*head);
  while ((node != NULL) && (node->data.key != k))
    {
      node = node->next;
    }

  return node;
}

void dll_delete(DoublyLinkedList** head, DoublyLinkedList* to_remove)
{
  if (to_remove->prev != NULL)
    {
      (to_remove->prev)->next = to_remove->next;
    }
  else
    {
      (*head) = to_remove->next;
    }
  if (to_remove->next != NULL)
    {
      (to_remove->next)->prev = to_remove->prev;
    }
}