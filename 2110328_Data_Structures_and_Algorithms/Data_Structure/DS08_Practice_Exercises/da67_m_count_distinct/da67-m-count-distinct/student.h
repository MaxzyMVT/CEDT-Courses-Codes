#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    // Write your code here
    std::set<T> S;
    while (a != b)
    {
        S.insert(*a);
        a++;
    }

    return S.size();
}

#endif