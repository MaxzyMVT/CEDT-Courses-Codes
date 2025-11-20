#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	queue<T> ans;

	size_t j = 0, i = 0, n = mSize;

	while (i < pos)
	{
		ans.push(front());
		pop();
		i++;
	}

	for (i = pos; i < n; i++, j++)
	{
		if (j < items.size())
			ans.push(items[j]);

		ans.push(front());
		pop();
	}

	while (j < items.size())
	{
		ans.push(items[j]);
		j++;
	}

	*this = ans;
}

#endif
