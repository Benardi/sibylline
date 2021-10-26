#include <bst.h>
#include <malloc.h>

void inorder_tree_walk(BinarySearchTree* node)
{
  if (node != NULL)
    {
      inorder_tree_walk(node->left);
      printf("%d \n", (node->data.key.i));
      inorder_tree_walk(node->right);
    }
}

void postorder_tree_walk(BinarySearchTree* node)
{
  if (node != NULL)
    {
      postorder_tree_walk(node->left);
      postorder_tree_walk(node->right);
      printf("%d \n", (node->data.key.i));
    }
}

void preorder_tree_walk(BinarySearchTree* node)
{
  if (node != NULL)
    {
      printf("%d \n", (node->data.key.i));
      preorder_tree_walk(node->left);
      preorder_tree_walk(node->right);
    }
}

BinarySearchTree* tree_insert(BinarySearchTree** root, Register reg,
                              int (*compare)(union Key, union Key))
{
  BinarySearchTree* node;
  BinarySearchTree* parent;
  BinarySearchTree* current;

  node = malloc(sizeof(BinarySearchTree));
  node->data = reg;
  node->right = NULL;
  node->left = NULL;
  node->p = NULL;

  current = (*root);
  parent = NULL;

  if ((*root) == NULL)
    {
      (*root) = node;
    }
  else
    {
      while (current != NULL)
        {
          parent = current;
          if (compare(node->data.key, current->data.key) == -1)
            {
              current = current->left;
            }
          else
            {
              current = current->right;
            }
        }

      node->p = parent;

      if (compare(node->data.key, parent->data.key) == -1)
        {
          parent->left = node;
        }
      else
        {
          parent->right = node;
        }
    }

  return node;
}

BinarySearchTree* tree_search(BinarySearchTree* node, union Key key,
                              int (*compare)(union Key, union Key))
{
  if ((node == NULL) || (compare(key, node->data.key) == 0))
    {
      return node;
    }
  else
    {
      if (compare(key, node->data.key) == -1)
        {
          return tree_search(node->left, key, compare);
        }
      else
        {
          return tree_search(node->right, key, compare);
        }
    }
}

BinarySearchTree* iterative_tree_search(BinarySearchTree* root, union Key key,
                                        int (*compare)(union Key, union Key))
{
  BinarySearchTree* node;

  node = root;
  while ((node != NULL) && (compare(key, node->data.key) != 0))
    {
      if (compare(key, node->data.key) == -1)
        {
          node = node->left;
        }
      else
        {
          node = node->right;
        }
    }
  return node;
}

BinarySearchTree* tree_minimum(BinarySearchTree* root)
{
  BinarySearchTree* node;

  node = root;
  if (node != NULL)
    {
      while (node->left != NULL)
        {
          node = node->left;
        }
    }
  return node;
}

BinarySearchTree* tree_maximum(BinarySearchTree* root)
{
  BinarySearchTree* node;

  node = root;
  if (node != NULL)
    {
      while (node->right != NULL)
        {
          node = node->right;
        }
    }
  return node;
}

BinarySearchTree* tree_successor(BinarySearchTree* node)
{
  if (node == NULL)
    {
      return NULL;
    }

  if (node->right != NULL)
    {
      return tree_minimum(node->right);
    }
  else
    {
      BinarySearchTree* scsr;

      scsr = node->p;
      while ((scsr != NULL) && (node == scsr->right))
        {
          node = scsr;
          scsr = scsr->p;
        }
      return scsr;
    }
}

BinarySearchTree* tree_predecessor(BinarySearchTree* node)
{
  if (node == NULL)
    {
      return NULL;
    }

  if (node->left != NULL)
    {
      return tree_maximum(node->left);
    }
  else
    {
      BinarySearchTree* scsr;

      scsr = node->p;
      while ((scsr != NULL) && (node == scsr->left))
        {
          node = scsr;
          scsr = scsr->p;
        }
      return scsr;
    }
}

static void transplant(BinarySearchTree** root, BinarySearchTree* node1,
                       BinarySearchTree* node2)
{
  if (node1->p == NULL)
    {
      (*root) = node2;
    }
  else if (node1 == node1->p->left)
    {
      node1->p->left = node2;
    }
  else
    {
      node1->p->right = node2;
    }
  if (node2 != NULL)
    {
      node2->p = node1->p;
    }
}

BinarySearchTree* tree_delete(BinarySearchTree** root, BinarySearchTree* node)
{
  BinarySearchTree* scsr = node;

  if (node->left == NULL) /* only a right child or no child */
    {
      transplant(root, node, node->right);
    }
  else if (node->right == NULL) /* only a left child */
    {
      transplant(root, node, node->left);
    }
  else /* both children */
    {
      scsr = tree_minimum(node->right);

      if (scsr->p != node) /* replace sucessor with its own child */
        {
          transplant(root, scsr, scsr->right);
          scsr->right = node->right;
          scsr->right->p = scsr;
        }

      transplant(root, node, scsr); /* replace node with successor */
      scsr->left = node->left;
      scsr->left->p = scsr;
    }

  return node;
}
