#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last)
{
  // write your code here

  // Faster? Version
  CP::vector<T> inserted;

  auto beg = this->begin();
  auto end = position;

  while (beg < end)
  {
    inserted.push_back(*beg);
    beg++;
  }

  while (first < last)
  {
    inserted.push_back(*first);
    first++;
  }

  beg = position;
  end = this->end();

  while (beg < end)
  {
    inserted.push_back(*beg);
    beg++;
  }

  *this = inserted;
}

#endif
