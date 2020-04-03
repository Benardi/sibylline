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

DoublyLinkedList* dll_search(DoublyLinkedList** head, void* key,
                             int (*compare)(void*, void*))
{
  DoublyLinkedList* node;

  node = (*head);
  while ((node != NULL) && compare(node->data.key, key) != 0)
    {
      node = node->next;
    }

  return node;
}

DoublyLinkedList* dll_get_nth(DoublyLinkedList** head, int n)
{
  int i;
  DoublyLinkedList* current;

  current = (*head);
  if (n > -1)
  {
    i = 0;
    while (current != NULL && i < n)
    {
      current = current->next;
      i++;
    } 
  }
  else
  {
    current = NULL;
  }

  return current;
}
DoublyLinkedList* dll_get_by_idx(DoublyLinkedList* curt, int curt_idx, int end)
{
  int i = curt_idx;
  DoublyLinkedList* current = curt;

  if (end > curt_idx)
  {
    while (current != NULL && i < end)
    {
      current = current->next;
      i++;
    } 
  }
  else if (end < curt_idx)
  {
    while (current != NULL && i > end)
    {
      current = current->prev;
      i--;
    } 
  }

  return current;
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
