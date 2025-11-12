#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <algorithm>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux)
{
    // You MAY use this function
    if (n == NULL)
    {
        aux = 0;
        return 0;
    }

    int heightL = 0, heightR = 0;
    int MxL = my_recur(n->left, heightL);
    int MxR = my_recur(n->right, heightR);

    aux = std::max(heightL, heightR) + 1;

    return std::max({heightL + heightR, MxL, MxR});
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    // write your code here
    if (empty())
        return -1;
    if (size() == 1)
        return 0;
    int h = 0;
    return my_recur(mRoot, h);
}

#endif
