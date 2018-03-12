#include "encoder.h"
#include "decoder.h"
#include "encoderlib.h"
#include "decoderlib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_N   100
#define MAX_M 10000

static int message[MAX_N];
static int N, NN;

static char encoded_message[MAX_M];
static int M;

static int output_message[MAX_N+1];
static int O;

void send_data(char c)
{
  if(M == 100*N) {
    printf("Encoded message too long.\n");
    exit(0);
  }
  if((c < 'a') || (c > 'z')) {
    printf("Bad encoded character.\n");
    exit(0);
  }
  encoded_message[M] = c;
  M++;
}

char read_data()
{
  if(NN==M) {
    printf("Reading too many encoded character.\n");
    exit(0);
  }
  NN++;
  return encoded_message[NN-1];
}

void output_data(int y)
{
  if(O == N)
    O++;
  if(O > N)
    return;
  output_message[O] = y;
  O++;
}

int main()
{
  int i,j;
  int correct;
  int p,r;

  scanf("%d",&N);
  for(i = 0; i < N; i++)
    scanf("%d",&message[i]);

  M = 0;
  encode(N,message);

  NN = 0;
  O = 0;
  decode(M);

  correct = 0;
  if(O==N) {
    correct = 1;
    for(i = 0; i < N; i++)
      if(message[i] != output_message[i]) {
	correct = 0;
	break;
      }
  }
  if(correct == 0)
    printf("Incorrect\n");
  else
    printf("Correct\n");
}
