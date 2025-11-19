#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// write your code here
	ensureCapacity(mSize + m);

	if (p < mSize - p)
	{
		int newFront = (mFront - m + mCap) % mCap;
		for (int i = 0; i < p; i++)
			mData[(newFront + i) % mCap] = mData[(mFront + i) % mCap];
		mFront = newFront;
	}
	else
	{
		int shiftSiz = mSize - p;
		for (int i = 0; i < shiftSiz; i++)
		{
			int from = mSize - 1 - i, to = from + m;
			mData[(mFront + to) % mCap] = mData[(mFront + from) % mCap];
		}
	}

	for (int i = p; i < p + m; i++)
		mData[(mFront + i) % mCap] = element;

	mSize += m;
}

#endif
