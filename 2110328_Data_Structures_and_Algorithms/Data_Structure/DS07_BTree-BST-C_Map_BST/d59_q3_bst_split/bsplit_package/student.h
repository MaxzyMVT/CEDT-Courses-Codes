#ifndef __STUDENT_H_
#define __STUDENT_H_

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
  node *parentLT = NULL;
  node *parentGTE = NULL;

  while (now != NULL)
  {
    if (mLess(now->data.first, val)) // Compare Lesser
    {
      *LT = now;
      LT = &(now->right);
      now->parent = parentLT;

      parentLT = now;
      now = now->right;
    }
    else // Compare Greater or Equal
    {
      *GTE = now;
      GTE = &(now->left);
      now->parent = parentGTE;

      parentGTE = now;
      now = now->left;
    }
  }

  *GTE = NULL;
  *LT = NULL;

  return result;
}

#endif
