#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m)
{
  // write your code here
  if (a > b)
    std::swap(a, b);
  if (a < begin() || b < begin() || a >= end() || b >= end() ||
      a + m - 1 < begin() || b + m - 1 < begin() || a + m - 1 >= end() || b + m - 1 >= end() || a + m - 1 >= b || m <= 0)
    return false;

  std::swap_ranges(a, a + m, b);
  return true;
}

#endif
