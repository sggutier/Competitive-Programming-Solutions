#include "hottest.h"
#include <stdio.h>

#define MAX_N 1000000

int T[MAX_N];

int main()
{
  int N,K;
  int r,secret;
  int i;

  scanf("%d %d",&N,&K);
  for(i = 0; i<N; i++)
    scanf("%d",&T[i]);
  scanf("%d",&secret);
  r = maxk(N,T,K);
  if(r==secret)
    printf("Correct %d\n",r);
  else
    printf("Incorrect %d should be %d\n",r,secret);
}
