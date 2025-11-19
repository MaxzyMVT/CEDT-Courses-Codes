#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
template <typename T>
void CP::list<T>::implant(CP::list<T> &other, int pos1, int pos2, int count)
{
    // Edit here.

    if (count == 0)
        return;

    auto itThis = begin(), itOtherSt = other.begin(), itOtherEn = other.begin();

    for (int i = 0; i < pos1; i++)
        itThis++;

    for (int i = 0; i < pos2; i++)
        itOtherSt++;

    for (int i = 0; i < pos2 + count; i++)
        itOtherEn++;

    node *p1 = itThis.ptr;
    node *p2st = itOtherSt.ptr;
    node *p2en = itOtherEn.ptr;

    p1->next->prev = p2en->prev;
    p2en->prev->next = p1->next;

    p2st->prev->next = p2en;
    p2en->prev = p2st->prev;

    p1->next = p2st;
    p2st->prev = p1;

    mSize += count;
    other.mSize -= count;
}
#endif