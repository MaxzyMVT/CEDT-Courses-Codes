#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::merge_greater(CP::queue<T> &other)
{
  // implement this from scratch

  if (other.mSize == 0 || this == &other)
    return;

  CP::queue<T> GT, LTE;
  GT.ensureCapacity(this->mSize + other.mSize);
  LTE.ensureCapacity(other.mSize);
  while (!this->empty())
  {
    T et = this->front();
    this->pop();
    GT.push(et);

    if (!other.empty())
    {
      T eo = other.front();
      other.pop();
      if (eo > et)
        GT.push(eo);
      else
        LTE.push(eo);
    }
  }

  // For address check
  this->ensureCapacity(GT.size());
  for (int i = 0; i < GT.size(); i++)
  {
    this->mData[i] = GT.mData[i];
  }

  this->mFront = 0;
  this->mSize = GT.size();

  other.ensureCapacity(LTE.size());
  for (int i = 0; i < LTE.size(); i++)
  {
    other.mData[i] = LTE.mData[i];
  }

  other.mFront = 0;
  other.mSize = LTE.size();
}

#endif