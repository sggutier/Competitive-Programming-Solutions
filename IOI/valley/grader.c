#include "valley.h"
#include "graderlib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_N  1000
#define MAX_M  100
#define LIMIT  50

static int data[MAX_N];
static int queries[MAX_M];
static int counter;
static int N;

int query(int i)
{
  counter++;
  return data[i];
}

int solution(int x)
{
  int i;
  for(i = 0; i < N; i++)
    if(data[i] == x)
      return 1;
  return 0;
}

int main()
{
  int i,m,q,s;
  scanf("%d",&N);
  for(i = 0; i < N; i++)
    scanf("%d",&data[i]);
  scanf("%d",&m);
  for(i = 0; i < m; i++) {
    scanf("%d",&queries[i]);
  }

  for(i = 0; i < m; i++) {
    s = solution(queries[i]);
    counter = 0;
    if(find(N,queries[i])!=s) {
      printf("Incorrect\n");
      return 0;
    } else if(counter > LIMIT) {
      printf("Too many questions\n");
      return 0;
    }
  }
  printf("Correct\n");
}
