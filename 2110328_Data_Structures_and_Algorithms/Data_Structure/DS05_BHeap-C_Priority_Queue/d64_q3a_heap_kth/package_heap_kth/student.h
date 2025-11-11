#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const
{
  // write your code here
  // can include anything

  std::vector<T> V(mData, mData + std::min((size_t)7, mSize));
  std::sort(V.begin(), V.end(), mLess);
  return *(V.end() - k);
};

#endif
