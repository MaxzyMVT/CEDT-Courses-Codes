#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure

#include <set>

template <typename T>
void CP::vector<T>::uniq()
{
  // do someting here

  CP::vector<T> Unique;
  std::set<T> bucket;

  auto beg = this->begin();
  auto end = this->end();

  while (beg < end)
  {
    auto ret = bucket.insert(*beg);
    if (ret.second) // Inserted?
    {
      Unique.push_back(*beg);
    }
    beg++;
  }

  *this = Unique;
}

#endif
