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

  // Recur func to assign new parents (try only one side)
  std::function<void(node *, node *, bool)> fix_parent;
  fix_parent = [&fix_parent](node *n, node *parent, bool fixLeft) -> void
  {
    if (n == NULL)
      return;
    n->parent = parent;
    if (fixLeft)
      fix_parent(n->left, n, true);
    else
      fix_parent(n->right, n, false);
  };

  fix_parent(mRoot, NULL, false);
  fix_parent(result.mRoot, NULL, true);

  return result;
}

#endif
