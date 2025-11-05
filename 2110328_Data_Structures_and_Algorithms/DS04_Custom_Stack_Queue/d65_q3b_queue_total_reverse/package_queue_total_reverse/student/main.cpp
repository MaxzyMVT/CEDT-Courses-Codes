#include "queue.h"
#include "student.h"
#include <iostream>

int main()
{
  CP::queue<int> q;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int element;
    std::cin >> element;
    q.push(element);
  }
  q.reverse();
  q.push(45);
  q.push(79);
  q.pop();
  q.reverse();
  q.pop();
  q.reverse();
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}