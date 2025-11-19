#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n)
{
  // write your code here
  // Get Size
  if (n == NULL)
    return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT> &left, map_bst<KeyT, MappedT, CompareT> &right)
{
  // write your code here
  if (empty())
    return std::pair<KeyT, MappedT>();

  node *LChild = mRoot->left;
  node *RChild = mRoot->right;

  if (LChild != NULL)
  {
    LChild->parent = NULL;
    left.mSize = process(LChild);
    left.mRoot = LChild;
  }

  if (RChild != NULL)
  {
    RChild->parent = NULL;
    right.mSize = process(RChild);
    right.mRoot = RChild;
  }

  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;

  return mRoot->data;
}

#endif
