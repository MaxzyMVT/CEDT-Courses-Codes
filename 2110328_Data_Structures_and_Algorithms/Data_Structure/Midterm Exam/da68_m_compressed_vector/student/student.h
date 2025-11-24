#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T>
void CP::CompressedVector<T>::expand(size_t capacity)
{
  // write your code here
  T *NmDataV = new T[capacity]();
  size_t *NmDataL = new size_t[capacity]();

  for (size_t i = 0; i < mSize; i++)
  {
    NmDataL[i] = mDataL[i];
    NmDataV[i] = mDataV[i];
  }

  delete[] mDataL;
  delete[] mDataV;

  mDataL = NmDataL;
  mDataV = NmDataV;

  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element)
{
  // write your code here

  if (mSize == 0)
  {
    ensureCapacity(1);
    mDataL[0] = 1;
    mDataV[0] = element;
    mSize = 1;

    return;
  }

  size_t i = 0;
  for (i = 0; i < mSize; i++)
  {
    if (index >= mDataL[i])
      index -= mDataL[i];
    else
      break;
  }

  if (i > mSize - 1 && mDataV[mSize - 1] != element)
  {
    ensureCapacity(mSize + 1);
    for (size_t p = mSize - 1; p >= i; p--)
    {
      mDataL[p] = mDataL[p - 1];
    }

    mDataV[i] = element;
    mDataL[i] = 1;
    mSize++;
  }
  else if (mDataV[i] == element)
  {
    mDataL[i]++;
  }
  else if (i > 0 && mDataV[i - 1] == element)
  {
    mDataL[i - 1]++;
  }
  else
  {
    ensureCapacity(mSize + 1);
    for (size_t p = mSize; p > i; p--)
    {
      mDataL[p] = mDataL[p - 1];
      mDataV[p] = mDataV[p - 1];
    }

    mDataV[i] = element;
    mDataL[i] = 1;
    mSize++;
  }
}

template <typename T>
T &CP::CompressedVector<T>::operator[](int index) const
{
  // write your code here

  for (size_t i = 0; i < mSize; i++)
  {
    if (index >= mDataL[i])
      index -= mDataL[i];
    else
      return mDataV[i];
  }
  return mDataV[0];
}

#endif
