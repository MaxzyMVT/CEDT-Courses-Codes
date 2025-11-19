#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "map_bst.h"
#include "student.h"
using namespace std;
// #pragma once

int main()
{
  CP::map_bst<int, int> tree1, tree2;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    tree1.insert({x, 1});
  }
  tree1.printResult();

  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    tree2.insert({x, 1});
  }
  tree2.printResult();

  tree1.modify(tree2);
  tree1.printResult();
  tree2.printResult();

  return 0;
}

/*
6 3
8 5 13 6 10 15
10 9 12

6 4
8 5 13 6 10 15
3 1 2 4

6 3
8 5 13 6 10 15
8 3 4

1 6
8
8 5 13 6 10 15

0 0

0 6
8 5 13 6 10 15

6 0
8 5 13 6 10 15

*/