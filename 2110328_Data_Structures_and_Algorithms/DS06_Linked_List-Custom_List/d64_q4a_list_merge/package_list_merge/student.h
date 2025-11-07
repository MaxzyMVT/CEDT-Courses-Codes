#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
  // write your code here
  for (auto &list : ls)
  {
    if (list.empty())
      continue;

    node *st = list.begin().ptr;
    node *en = (--list.end()).ptr;

    (--end()).ptr->next = st;
    en->next = end().ptr;

    st->prev = (--end()).ptr;
    end().ptr->prev = en;

    mSize += list.mSize;

    list.mHeader->prev = list.mHeader;
    list.mHeader->next = list.mHeader;
    list.mSize = 0;
  }
}
#endif
