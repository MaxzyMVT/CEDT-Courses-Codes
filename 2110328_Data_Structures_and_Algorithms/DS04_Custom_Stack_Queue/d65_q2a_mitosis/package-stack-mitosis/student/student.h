#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    int len = b - a + 1;
    if (len <= 0)
        return;
    size_t newSize = mSize + len;
    size_t B_idx = mSize - 1 - a;
    size_t A_idx = mSize - 1 - b;

    if (newSize > mCap)
    {
        if (mCap * 2 >= newSize)
            expand(mCap * 2);
        else
            expand(newSize);
    }

    for (size_t k = newSize - 1, i = mSize - 1; k > A_idx; k--)
    {
        T element = mData[i];

        mData[k] = element;

        if (i < A_idx || i > B_idx || (newSize - a - k) % 2 == 0)
            i--;
    }

    mSize = newSize;
}

#endif