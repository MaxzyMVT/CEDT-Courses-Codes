void replace(const T &x, list<T> &y)
{
  // write your code here
  if (empty())
    return;
  for (auto it = begin(); it != end(); it++)
  {
    if (*it != x)
      continue;

    node *n = it.ptr;
    if (y.empty())
    {
      it = erase(it).ptr->prev;
      continue;
    }

    list<T> ls(y);

    n->prev->next = ls.begin().ptr;
    n->next->prev = (--ls.end()).ptr;
    ls.begin().ptr->prev = n->prev;
    (--ls.end()).ptr->next = n->next;

    delete n;
    mSize += y.mSize - 1;

    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;
    ls.mSize = 0;
  }
}
