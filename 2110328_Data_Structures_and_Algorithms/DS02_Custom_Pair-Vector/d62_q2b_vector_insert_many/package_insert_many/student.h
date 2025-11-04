#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
  // write your code here
  CP::vector<T> inserted;

  sort(data.begin(), data.end());

  auto beg = this->begin();
  auto end = this->end();

  auto begD = data.begin();
  auto endD = data.end();

  while (beg < end || begD < endD)
  {
    int idx = beg - this->begin();

    if (begD < endD && idx == begD->first)
    {
      inserted.push_back(begD->second);
      begD++;
    }
    else
    {
      inserted.push_back(*beg);
      beg++;
    }
  }

  *this = inserted;
}

#endif
