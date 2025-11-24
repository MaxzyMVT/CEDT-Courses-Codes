#include "priority_queue.h"
#include <utility>
#include <queue>

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k)
{

  std::queue<std::pair<size_t, size_t>> Q;

  if (k * 2 + 2 < mSize)
    Q.push({k * 2 + 1, 1});

  while (Q.size())
  {
    auto [p, len] = Q.front();
    Q.pop();

    std::swap(mData[p + len], mData[p]);

    if (p * 2 + 2 < mSize)
    {
      Q.push({p * 2 + 1, len * 2});
      Q.push({p * 2 + 2, len * 2});
    }
  }

  return;
}