
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls)
{
    /*

        “In war, then, let your great object be victory, not lengthy campaigns.”
        ― Sun Tzu, The Art of War

    */

    auto itA = this->begin();
    auto headA = this->end();
    auto itB = ls.begin();
    auto headB = ls.end();
    node *now = mHeader;

    while (itA != headA || itB != headB)
    {
        if (itA != headA)
        {
            node *A = itA.ptr;
            ++itA;

            now->next = A;
            A->prev = now;
            now = now->next;
        }

        if (itB != headB)
        {
            node *B = itB.ptr;
            ++itB;

            now->next = B;
            B->prev = now;
            now = now->next;
        }
    }

    now->next = mHeader;
    mHeader->prev = now;

    mSize += ls.size();

    ls.mSize = 0;
    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;
}

#endif
