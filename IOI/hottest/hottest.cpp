#include "hottest.h"
#include <algorithm>
using namespace std ;

int maxk(int N, int T[], int K)
{
	int i;
	int sum = 0, res=0;
	for( i=0; i<N; i++ ) {
		sum += T[i];
		if( i>=K )
			sum -= T[i-K] ;
		res = max( res, sum ) ;
	}
	
	return res;
}
