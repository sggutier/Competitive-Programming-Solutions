#include "decoder.h"
#include "decoderlib.h"

void decode(int M)
{
  int i;
  char y;
  for(i=0; i<M; i++) {
    y = read_data();
    output_data(1);
  }
}
