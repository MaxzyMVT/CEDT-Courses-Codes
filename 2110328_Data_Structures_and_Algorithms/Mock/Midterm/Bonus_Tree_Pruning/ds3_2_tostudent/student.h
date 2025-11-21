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

	bool isGrafted = size() == 1 && compare(other.mRoot->data.first, mRoot->data.first == 0);

	if (!isGrafted && size() > 1)
	{
		graft(mRoot, other.mRoot, other.size());
		prune(mRoot->left, mRoot->data.first, mRoot->data.first, 1, 0);
		prune(mRoot->right, mRoot->data.first, mRoot->data.first, 0, 1);
	}
	else
	{
		mRoot = other.mRoot;
		mSize = other.mSize;
	}

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
	KeyT now = n->data.first;
	KeyT val = m->data.first;
	int cmp = compare(now, val);

	if (cmp == 0)
	{
		if (n->left || n->right)
			return;
		if (n->parent->left == n)
		{
			n->parent->left = m;
			m->parent = n->parent;
		}
		else
		{
			n->parent->right == n;
			m->parent = n->parent;
		}
		mSize += otherSize - 1;
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
	else
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
		return;

	KeyT now = n->data.first;

	bool isWrong = false;

	if (mLess(now, lower))
	{
		if()
	}
		lower = now;
	if (mLess(upper, now))
		upper = now;

	prune(n->left, )

		return;
}

#endif
