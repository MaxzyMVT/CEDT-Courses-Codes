#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::jenga(char c, int a)
{
    // Your code here
    if (c == 'p')
    {
        size_t pos = mSize - a - 1;
        T val = mData[pos];
        for (size_t i = pos; i < mSize - 1; i++)
        {
            mData[i] = mData[i + 1];
        }
        mData[mSize - 1] = val;
    }
    else if (c == 'c')
    {
        mSize -= a;
    }
}

#endif