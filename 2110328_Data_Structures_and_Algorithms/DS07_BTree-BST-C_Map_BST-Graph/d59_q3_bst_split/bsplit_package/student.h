#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <functional>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val)
{
  // your code here
  CP::map_bst<KeyT, MappedT, CompareT> result;
  result.mLess = mLess;

  if (mSize == 0)
    return result;

  node *now = mRoot;
  mRoot = NULL;

  node **LT = &mRoot;         // where to add to Lesser Subtree
  node **GTE = &result.mRoot; // where to add to Greater or Equal Subtree

  while (now != NULL)
  {
    if (mLess(now->data.first, val)) // Compare Lesser
    {
      node *prev = *LT;
      *LT = now;
      LT = &(now->right);
      now = now->right;
    }
    else // Compare Greater or Equal
    {
      *GTE = now;
      GTE = &(now->left);
      now = now->left;
    }
  }

  *GTE = NULL;
  *LT = NULL;

  // Recur func to assign new parents
  std::function<void(node *, node *)> fix_parent;
  fix_parent = [&fix_parent](node *n, node *parent) -> void
  {
    if (n == NULL)
      return;
    n->parent = parent;
    fix_parent(n->left, n);
    fix_parent(n->right, n);
  };

  fix_parent(mRoot, NULL);
  fix_parent(result.mRoot, NULL);

  return result;
}

#endif
