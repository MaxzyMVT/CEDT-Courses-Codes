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

	if (other.mSize == 0 || mSize == 0)
		return;

	bool isMoved = false;

	if (mSize == 1 && compare(mRoot->data.first, mRoot->data.first) == 0)
		isMoved = true;

	graft(mRoot, other.mRoot, other.mSize);

	if (other.mRoot->parent != NULL || isMoved)
	{
		other.mRoot = NULL;
		other.mSize = 0;
	}

	return;
}

// you may use this function to find the grafting point
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

#endif
