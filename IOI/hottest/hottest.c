#include "hottest.h"

int maxk(int N, int T[], int K)
{
  int i;
  int sum = 0;
  for(i = 0; i<K; i++)
    sum += T[i];
  return sum;
}
