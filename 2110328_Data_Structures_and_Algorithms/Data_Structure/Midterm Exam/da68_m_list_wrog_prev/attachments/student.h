#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template <typename T>
size_t CP::list<T>::fix_wrong()
{
  size_t cnt = 0;
  node *P = mHeader;
  node *N = mHeader->next;

  do
  {
    if (N->prev != P)
    {
      N->prev = P;
      cnt++;
    }

    P = N;
    N = N->next;
  } while (P != mHeader);

  return cnt;
}

#endif