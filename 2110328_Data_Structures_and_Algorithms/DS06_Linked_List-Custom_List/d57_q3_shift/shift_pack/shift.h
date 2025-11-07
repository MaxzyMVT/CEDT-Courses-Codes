void shift(int k)
{
	// TODO: Add your code here

	if (k < 0)
	{
		k = -k;
		k %= mSize;
		k = mSize - k;
	}
	k %= mSize;

	if (k == 0)
		return;

	node *beg = begin().ptr;
	node *bend = (--end()).ptr;
	node *it1, *it2 = beg;

	while (k--)
		it2 = it2->next;
	it1 = it2->prev;

	mHeader->next = it2;
	it2->prev = mHeader;

	it1->next = mHeader;
	mHeader->prev = it1;

	bend->next = beg;
	beg->prev = bend;
}
