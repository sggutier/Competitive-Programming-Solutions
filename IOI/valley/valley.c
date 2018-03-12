#include "valley.h"
#include "graderlib.h"

int find(int N, int x)
{
  int i;
  for(i = 0; i < N; i++)
    if(query(i)==x)
      return 1;
  return 0;
}
