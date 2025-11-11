#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void CP::queue<T>::move_to_front(size_t pos)
{
    // write your code here

    T element = mData[(mFront + pos) % mCap];

    for (size_t i = mFront + pos; i > mFront; i--)
    {
        mData[i % mCap] = mData[(i % mCap - 1) % mCap];
    }

    mData[mFront] = element;
}

#endif