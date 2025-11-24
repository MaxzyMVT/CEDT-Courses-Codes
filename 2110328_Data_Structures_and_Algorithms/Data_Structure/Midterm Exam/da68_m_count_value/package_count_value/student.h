#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>

std::vector<size_t> count_value(const std::map<long long, int> &data, const std::vector<std::pair<int, int>> &queries)
{
  std::vector<size_t> r;
  // write your code here

  std::vector<int> V;

  for (auto [key, val] : data)
  {
    V.emplace_back(val);
  }

  sort(V.begin(), V.end());

  int n = queries.size();
  r.resize(n);
  for (int i = 0; i < n; i++)
  {
    auto [a, b] = queries[i];
    auto itL = lower_bound(V.begin(), V.end(), a);
    auto itU = upper_bound(V.begin(), V.end(), b);

    r[i] = itU - itL;
  }

  return r;
}

#endif
