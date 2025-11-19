#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"
#include <set>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator CP::map_bst<KeyT, MappedT, CompareT>::recursive(node *n, CP::map_bst<KeyT, MappedT, CompareT>::iterator p, CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const
{
    // You may need this function
    if (n == NULL)
        return iterator(NULL);

    bool nLp = mLess(n->data.first, p->first);
    bool pLn = mLess(p->first, n->data.first);
    bool nLq = mLess(n->data.first, q->first);
    bool qLn = mLess(q->first, n->data.first);

    int cmpP, cmpQ;

    if (pLn)
        cmpP = 1;
    else if (nLp)
        cmpP = -1;
    else
        cmpP = 0;

    if (qLn)
        cmpQ = 1;
    else if (nLq)
        cmpQ = -1;
    else
        cmpQ = 0;

    if (cmpP >= 0 && cmpQ <= 0)
        return iterator(n);
    if (cmpP < 0)
        return recursive(n->right, p, q);
    if (cmpQ > 0)
        return recursive(n->left, p, q);

    return iterator(NULL);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator CP::map_bst<KeyT, MappedT, CompareT>::lca(CP::map_bst<KeyT, MappedT, CompareT>::iterator p, CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const
{
    // Write your code here
    bool pLq = mLess(p->first, q->first);
    bool qLp = mLess(q->first, p->first);

    if (pLq)
        return recursive(mRoot, p, q);
    if (qLp)
        return recursive(mRoot, q, p);
    return p;
}

#endif
