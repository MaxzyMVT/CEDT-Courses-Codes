#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"

// this is the modify() function to be submitted
template <typename KeyT,
		  typename MappedT,
		  typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::modify(
	CP::map_bst<KeyT, MappedT, CompareT> &other)
{
	// your code here
	if (other.size() <= 0 || size() <= 0)
		return;

	bool isGrafted = size() == 1 && compare(other.mRoot->data.first, mRoot->data.first) == 0;

	graft(mRoot, other.mRoot, other.size());
	prune(mRoot->left, mRoot->data.first, mRoot->data.first, 1, 0);
	prune(mRoot->right, mRoot->data.first, mRoot->data.first, 2, 0);

	if (other.mRoot->parent != NULL || isGrafted)
	{
		other.mSize = 0;
		other.mRoot = NULL;
	}

	return;
}

// you may use this function to traverse and graft
template <typename KeyT,
		  typename MappedT,
		  typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::graft(
	CP::map_bst<KeyT, MappedT, CompareT>::node *n, CP::map_bst<KeyT, MappedT, CompareT>::node *m, size_t otherSize)
{
	// your code here
	KeyT dataThis = n->data.first;
	KeyT dataOther = m->data.first;

	int cmp = compare(dataOther, dataThis);

	if (cmp == 0)
	{
		if (n->left != NULL || n->right != NULL)
			return;
		if (mRoot == n)
		{
			mRoot = m;
			mSize = otherSize;
			m->parent = NULL;
		}
		else if (n->parent->left == n)
		{
			n->parent->left = m;
			m->parent = n->parent;
			mSize += otherSize - 1;
		}
		else if (n->parent->right == n)
		{
			n->parent->right = m;
			m->parent = n->parent;
			mSize += otherSize - 1;
		}

		delete n;
	}
	else if (cmp < 0)
	{
		if (n->left == NULL)
		{
			n->left = m;
			m->parent = n;
			mSize += otherSize;
		}
		else
			graft(n->left, m, otherSize);
	}
	else if (cmp > 0)
	{
		if (n->right == NULL)
		{
			n->right = m;
			m->parent = n;
			mSize += otherSize;
		}
		else
			graft(n->right, m, otherSize);
	}

	return;
}

// you may use this function to traverse and prune
template <typename KeyT,
		  typename MappedT,
		  typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::prune(
	CP::map_bst<KeyT, MappedT, CompareT>::node *n, KeyT upper, KeyT lower, int aux1, int aux2)
{
	// your code here
	if (!n)
		return 0;

	KeyT now = n->data.first;
	int cmpL = compare(now, lower);
	int cmpU = compare(now, upper);

	if (aux2 || cmpL <= 0 && aux1 & 2 || cmpU >= 0 && aux1 & 1)
	{
		aux2 = 1;
		if (n->parent->left == n)
		{
			n->parent->left = NULL;
		}
		else
		{
			n->parent->right = NULL;
		}
	}

	prune(n->left, now, lower, aux1 | 1, aux2);
	prune(n->right, upper, now, aux1 | 2, aux2);

	if (aux2)
	{
		delete n;
		mSize--;
	}

	return 0;
}

#endif
