void splitList(list<T> &list1, list<T> &list2)
{
    // Add your code here
    if (empty())
        return;

    size_t L1Size = (mSize + 1) / 2;
    size_t L2Size = mSize - L1Size;

    list1.mSize += L1Size;

    node *last1 = mHeader;
    while (L1Size--)
        last1 = last1->next;

    node *first2 = last1->next;

    // List 1 Connect
    (--list1.end()).ptr->next = begin().ptr;
    begin().ptr->prev = (--list1.end()).ptr;
    last1->next = list1.end().ptr;
    list1.end().ptr->prev = last1;

    if (L2Size != 0)
    {
        // List 2 Connect
        (--list2.end()).ptr->next = first2;
        first2->prev = (--list2.end()).ptr;
        (--end()).ptr->next = list2.end().ptr;
        list2.end().ptr->prev = (--end()).ptr;

        list2.mSize += L2Size;
    }

    this->mHeader->prev = this->mHeader;
    this->mHeader->next = this->mHeader;
    this->mSize = 0;
}
