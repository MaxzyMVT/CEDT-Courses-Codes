#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

#include "map_bst.h"
#include "student.h"
#include <algorithm>
// #pragma once

int main()
{
  for (int val = 1; val <= 10; val++)
  {

    printf("\n\n\n-------------------------\nChecking parem = %d...\n-------------------------\n", val);

    // std::vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};
    // std::vector<int> v = {30, 70, 40, 20, 10, 80, 50, 60, 90, 100};
    std::vector<int> v = {3, 2, 8, 1, 5, 9, 4, 6, 7};
    // std::reverse(v.begin(), v.end());

    // add value from v to m
    CP::map_bst<int, int> m1, m2;
    for (auto x : v)
    {
      m1[x] = -x;
    }

    // save address
    std::unordered_map<int, void *> address;
    m1.save_address(address);

    printf("The \"original\"  tree\n");
    m1.print();
    m2 = m1.split(val);

    // check
    bool ok = true;
    for (auto &x : v)
    {
      if (x < val && (m1.find(x) == m1.end() || m2.find(x) != m2.end()))
      {
        ok = false;
        break;
      }
      if (x >= val && (m2.find(x) == m2.end() || m1.find(x) != m1.end()))
      {
        ok = false;
        break;
      }
    }

    printf("Start checking...\n");
    printf("The \"less than\"  tree\n");
    m1.print();
    printf("The \"equal or more than\" tree\n");
    m2.print();

    // Grader's Check Address
    if (!m1.check_address(address))
      ok = false;
    if (!m2.check_address(address))
      ok = false;

    if (ok)
    {
      printf("OK\n");
    }
    else
    {
      printf("WRONG\n");
    }
  }

  return 0;
}
/*
          3
        2        8
      1       5    9
            4  6
                7
parem 5
LEQ Parent 8
LT Child 4
*/