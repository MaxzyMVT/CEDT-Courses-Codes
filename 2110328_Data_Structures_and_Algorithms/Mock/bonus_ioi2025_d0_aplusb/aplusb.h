#ifndef __APLUSB_H_
#define __APLUSB_H_
#include <vector>

std::vector<int> A, B;

void initialize(std::vector<int> A, std::vector<int> B)
{
  // you code here
  ::A = A;
  ::B = B;
  return;
}

int answer_question(int i, int j)
{
  // you code here
  return A[i] + B[j];
}

#endif