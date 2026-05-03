#include <sll.h>
#include <stdlib.h>

SinglyLinkedList* sll_insert(SinglyLinkedList** head, IntRegister reg)
{
  SinglyLinkedList* node;
  node = malloc(sizeof(SinglyLinkedList));
  node->data = reg;
  node->next = (*head);

  (*head) = node;
  return node;
}

SinglyLinkedList* sll_search(SinglyLinkedList** head, int key,
                             int (*compare)(int, int))
{
  SinglyLinkedList* node;

  node = (*head);
  while ((node != NULL) && compare(node->data.key, key) != 0)
    {
      node = node->next;
    }
  return node;
}

void sll_delete(SinglyLinkedList** head, SinglyLinkedList* to_remove)
{
  if ((*head) != NULL)
    {
      if (to_remove == (*head))
        {
          (*head) = (*head)->next;
        }
      else
        {
          SinglyLinkedList* node;

          node = (*head);
          while ((node->next != NULL) && (node->next != to_remove))
            {
              node = node->next;
            }
          if (node->next != NULL)
            {
              node->next = (node->next)->next;
            }
        }
    }
}
