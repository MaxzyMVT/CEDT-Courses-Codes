#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos)
{
  // write your code here
  CP::vector<T> deleted;

  auto beg = this->begin();
  auto end = this->end();

  auto begP = pos.begin();
  auto endP = pos.end();

  while (beg < end)
  {
    int idx = beg - this->begin();

    if (begP < endP && idx == *begP)
      begP++;
    else
      deleted.push_back(*beg);
    beg++;
  }

  *this = deleted;
}

#endif