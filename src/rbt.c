#include <malloc.h>
#include <rbt.h>

void init_rbtree(RedBlackTree** root, RedBlackTree* nil)
{
  nil->p = nil;
  nil->left = nil;
  nil->right = nil;
  nil->color = BLACK;

  (*root) = nil;
}

void left_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node)
{
  RedBlackTree* right_child;

  right_child = node->right; /* set y */
  node->right = right_child->left;

  if (right_child->left != nil)
    {
      right_child->left->p = node;
    }

  right_child->p = node->p;

  if (node->p == nil)
    {
      (*root) = right_child;
    }
  else if (node == (node->p)->left)
    {
      (node->p)->left = right_child;
    }
  else
    {
      (node->p)->right = right_child;
    }
  right_child->left = node;
  node->p = right_child;
}

void right_rotate(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node)
{
  RedBlackTree* left_child;

  left_child = node->left;
  node->left = left_child->right;

  if (left_child->right != nil)
    {
      left_child->right->p = node;
    }

  left_child->p = node->p;

  if (node->p == nil)
    {
      (*root) = left_child;
    }
  else if (node == (node->p)->left)
    {
      (node->p)->left = left_child;
    }
  else
    {
      (node->p)->right = left_child;
    }

  left_child->right = node;
  node->p = left_child;
}

static void rb_insert_fixup(RedBlackTree** root, RedBlackTree* nil,
                            RedBlackTree* node)
{
  RedBlackTree* uncle;

  while (node->p->color == RED)
    {
      if (node->p == (node->p->p)->left) /* parent is a left child */
        {
          uncle = (node->p->p)->right;

          if (uncle->color == RED)
            {
              uncle->color = BLACK;
              node->p->color = BLACK;
              node->p->p->color = RED;
              node = node->p->p;
            }
          else
            {
              if (node == (node->p)->right)
                {
                  node = node->p;
                  left_rotate(root, nil, node);
                }

              node->p->color = BLACK;
              node->p->p->color = RED;
              right_rotate(root, nil, node->p->p);
            }
        }
      else /* parent is a right child */
        {
          uncle = (node->p->p)->left;

          if (uncle->color == RED)
            {
              uncle->color = BLACK;
              node->p->color = BLACK;
              node->p->p->color = RED;
              node = node->p->p;
            }
          else
            {
              if (node == (node->p)->left)
                {
                  node = node->p;
                  right_rotate(root, nil, node);
                }

              node->p->color = BLACK;
              node->p->p->color = RED;
              left_rotate(root, nil, node->p->p);
            }
        }
    }

  (*root)->color = BLACK;
}

RedBlackTree* rb_insert(RedBlackTree** root, RedBlackTree* nil, Register reg,
                        int (*compare)(void*, void*))
{
  RedBlackTree* node;
  RedBlackTree* parent;
  RedBlackTree* current;

  node = malloc(sizeof(RedBlackTree));
  node->data = reg;
  node->color = RED;
  node->right = nil;
  node->left = nil;
  node->p = nil;

  current = (*root);
  parent = nil;

  if ((*root) == nil)
    {
      (*root) = node;
    }
  else
    {
      while (current != nil)
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

  rb_insert_fixup(root, nil, node);

  return node;
}

static void rb_transplant(RedBlackTree** root, RedBlackTree* nil,
                          RedBlackTree* node1, RedBlackTree* node2)
{
  if (node1->p == nil)
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
  node2->p = node1->p;
}

RedBlackTree* rb_tree_minimum(RedBlackTree* root, RedBlackTree* nil)
{
  RedBlackTree* node;

  node = root;
  if (node != nil)
    {
      while (node->left != nil)
        {
          node = node->left;
        }
    }
  return node;
}

static void rb_delete_fixup(RedBlackTree** root, RedBlackTree* nil,
                            RedBlackTree* node, RedBlackTree* parent)
{
  RedBlackTree* sibling;

  while ((node != (*root)) && (node->color == BLACK))
    {
      if (node == parent->left) /* node is left child */
        {
          sibling = parent->right;
          if (sibling->color == RED)
            {
              sibling->color = BLACK;
              parent->color = RED;
              left_rotate(root, nil, parent);
              sibling = parent->right;
            }
          if ((sibling->left->color == BLACK) &&
              (sibling->right->color == BLACK))
            {
              sibling->color = RED;
              node = parent;
              parent = node->p;
            }
          else
            {
              if (sibling->right->color == BLACK)
                {
                  sibling->left->color = BLACK;
                  sibling->color = RED;
                  right_rotate(root, nil, sibling);
                  sibling = parent->right;
                }

              sibling->color = parent->color;
              parent->color = BLACK;
              sibling->right->color = BLACK;
              left_rotate(root, nil, parent);
              node = (*root);
              parent = node->p;
            }
        }
      else
        {
          sibling = parent->left;
          if (sibling->color == RED)
            {
              sibling->color = BLACK;
              parent->color = RED;
              right_rotate(root, nil, parent);
              sibling = parent->left;
            }
          if ((sibling->left->color == BLACK) &&
              (sibling->right->color == BLACK))
            {
              sibling->color = RED;
              node = parent;
              parent = node->p;
            }
          else
            {
              if (sibling->left->color == BLACK)
                {
                  sibling->right->color = BLACK;
                  sibling->color = RED;
                  left_rotate(root, nil, sibling);
                  sibling = parent->left;
                }

              sibling->color = parent->color;
              parent->color = BLACK;
              sibling->left->color = BLACK;
              right_rotate(root, nil, parent);
              node = (*root);
              parent = node->p;
            }
        }
    }
  node->color = BLACK;
}

void rb_delete(RedBlackTree** root, RedBlackTree* nil, RedBlackTree* node)
{
  RedBlackTree* scsr; /* the node either removed or moved */
  RedBlackTree* rplc;
  RedBlackTree* parent;
  Color orig_color;

  scsr = node;
  orig_color = scsr->color;

  if (node->left == nil) /* only a right child or no child */
    {
      parent = node->p;
      rplc = node->right;
      rb_transplant(root, nil, node, node->right);
    }
  else if (node->right == nil) /* only a left child */
    {
      parent = node->p;
      rplc = node->left;
      rb_transplant(root, nil, node, node->left);
    }
  else /* both children */
    {
      scsr = rb_tree_minimum(node->right, nil);
      orig_color = scsr->color;
      rplc = scsr->right;
      parent = scsr->p;

      if (scsr->p == node) /* replace sucessor for its own child */
        {
          rplc->p = scsr;
          parent = scsr;
        }
      else /* replace sucessor for its child */
        {
          rb_transplant(root, nil, scsr, scsr->right);
          scsr->right = node->right;
          scsr->right->p = scsr;
        }
      rb_transplant(root, nil, node, scsr); /* replace node for successor */
      scsr->left = node->left;
      scsr->left->p = scsr;
      scsr->color = node->color;
    }
  if (orig_color == BLACK)
    {
      rb_delete_fixup(root, nil, rplc, parent);
    }
}
