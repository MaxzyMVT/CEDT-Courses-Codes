#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  queue<T> ans;
  auto p = pos.begin();
  sort(pos.begin(), pos.end());

  for (int i = mFront; i <= mFront + mSize - 1; i++)
  {
    int rel_i = i - mFront;
    if (p != pos.end() && *p == rel_i)
      p++;
    else
      ans.push(mData[i % mCap]);
  }
  *this = ans;
}

#endif
