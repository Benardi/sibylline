#include <csll.h>
#include <malloc.h>
#include <stdbool.h>

CircularSinglyLinkedList* csll_insert_begin(CircularSinglyLinkedList** tail,
                                            Register reg)
{
  CircularSinglyLinkedList* node;

  node = malloc(sizeof(CircularSinglyLinkedList));
  node->data = reg;

  if ((*tail) == NULL)
    {
      (*tail) = node;
      (*tail)->next = node;
    }
  else
    {
      node->next = (*tail)->next;
      (*tail)->next = node;
    }

  return node;
}

CircularSinglyLinkedList* csll_insert_end(CircularSinglyLinkedList** tail,
                                          Register reg)
{
  CircularSinglyLinkedList* node;

  node = malloc(sizeof(CircularSinglyLinkedList));
  node->data = reg;

  if ((*tail) == NULL)
    {
      (*tail) = node;
      (*tail)->next = node;
    }
  else
    {
      node->next = (*tail)->next;
      (*tail)->next = node;
      (*tail) = node;
    }

  return node;
}

CircularSinglyLinkedList* csll_search(CircularSinglyLinkedList** tail, Key k)
{
  if ((*tail) == NULL)
    {
      return NULL;
    }
  if ((*tail)->data.key == k)
    {
      return (*tail);
    }
  else
    {
      CircularSinglyLinkedList* node;
      node = (*tail)->next;
      while (node != (*tail) && (node->data.key != k))
        {
          node = node->next;
        }

      if (node == (*tail))
        {
          node = NULL;
        }

      return node;
    }
}

void csll_delete(CircularSinglyLinkedList** tail,
                 CircularSinglyLinkedList* to_remove)
{
  if ((*tail) != NULL)
    {
      bool is_tail;
      is_tail = (to_remove == (*tail));

      if (is_tail && (to_remove->next == to_remove))
        {
          (*tail) = NULL;
        }
      else
        {
          CircularSinglyLinkedList* node;

          if (is_tail)
            {
              node = (*tail)->next;

              while ((node->next != (*tail)))
                {
                  node = node->next;
                }

              node->next = (*tail)->next;
              (*tail) = node;
            }
          else
            {
              node = (*tail);

              while ((node->next != (*tail)) && (node->next != to_remove))
                {
                  node = node->next;
                }
              node->next = node->next->next;
            }
        }
    }
}
