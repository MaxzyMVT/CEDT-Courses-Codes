#include "queue.h"
#include "student.h"
#include <cstdio>
#include <ios>
#include <iostream>
#include <string>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int A_count, B_count;
  std::cin >> A_count >> B_count;
  CP::queue<int> A(A_count * 1.5);
  CP::queue<int> B(B_count * 1.5);
  for (int j = 0; j < A_count; j++)
  {
    int a;
    std::cin >> a;
    A.push(a);
  }
  for (int j = 0; j < B_count; j++)
  {
    int b;
    std::cin >> b;
    B.push(b);
  }
  std::string cmd;
  while (true)
  {
    std::cin >> cmd;
    char self, other;
    if (cmd == "q")
      break;
    std::cin >> self;
    auto self_ref = (self == 'A') ? &A : &B;
    if (cmd == "p")
    {
      self_ref->print_check();
    }
    else if (cmd == "d")
      self_ref->pop();
    else
    {
      if (cmd == "e")
      {
        int k;
        std::cin >> k;
        self_ref->push(k);
      }
      else if (cmd == "g")
      {
        std::cin >> other;
        auto *other_ref = (other == 'A') ? &A : &B;
        self_ref->merge_greater(*other_ref);
      }
    }
  }
  return 0;
}

/*
10 5
1 5 7 3 10 9 4 3 -1 0
-5 8 12 2 11
p A
g A B
p B
d A
d A
p A
q

10 5
1 5 7 3 10 9 4 3 -1 0
-5 8 12 2 11
p A
g B A
p B
p A
d A
d A
p A
q


5 0
5 7 -9 3 4
p A
g A B
p A
e B 8
d A
g A B
d A
p A
q

5 0
5 7 -9 3 4
p A
g B A
p A
e B 8
d A
g A B
d A
p A
q

4 2
6 9 -10 2
5 10
e B 8
e B 12
d A
d A
g B A
p A
p B
q

0 0
p A
g A A
p A


*/