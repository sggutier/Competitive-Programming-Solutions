#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005
#define inf (1<<30)

struct bitMax {
	int dat[lim] ;
	bitMax() {
		for( int i=0; i<lim; i++ ) {
			dat[i] = -inf ;
		}
	}
	void mete( int pos, int nov ) {
		for( ; pos<lim; pos+=( pos & -pos)   )
			dat[pos] = max( dat[pos], nov ) ;
	}
	int carg( int pos ) {
		int res = -inf ;
		for( ; pos>0; pos -= (pos & -pos)  )
			res = max( dat[pos], res ) ;
		return res ;
	}
};

struct bitMin {
	int dat[lim] ;
	bitMin() {
		for( int i=0; i<lim; i++ ) {
			dat[i] = inf ;
		}
	}
	void mete( int pos, int nov ) {
		for( ; pos<lim; pos+=( pos & -pos)   )
			dat[pos] = min( dat[pos], nov ) ;
	}
	int carg( int pos ) {
		int res = inf ;
		for( ; pos>0; pos -= (pos & -pos)  )
			res = min( dat[pos], res ) ;
		return res ;
	}
};

int N, L ;
int arr[lim][2] ;
int dp[lim] ;
bitMax subSec ;

int bs( int ini, int fin ) {
	int piv ;
	while( ini<fin ) {
		piv = (ini+fin)/2 ;
		if( subSec.carg(piv)+dp[piv+1] < subSec.carg(piv+1)+dp[piv+2] )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	return subSec.carg(ini)+dp[ini+1] ;
}

int main() {
	freopen( "bookshelf.in", "r", stdin ) ;
	freopen( "bookshelf.out", "w", stdout ) ;
	
	int carg, posCarg ;
	
	scanf("%d%d", &N, &L  ) ;
	for( int i=1; i<=N; i++ ) 
		scanf("%d%d", &arr[i][0], &arr[i][1] ) ;
	
	subSec.mete( N+1, 0 ) ;
	carg = 0 ;
	posCarg = N ;
	for( int i=N; i; i-- ) {
		subSec.mete( i, arr[i][0] ) ;
		carg += arr[i][1] ;
		while( carg>L ) {
			carg -= arr[posCarg--][1] ;
		}
		while( posCarg>i && subSec.carg(posCarg)+dp[posCarg+1]>=subSec.carg(posCarg-1)+dp[posCarg] ) {
			carg -= arr[posCarg--][1] ;
		}
		dp[i] = subSec.carg(posCarg) + dp[posCarg+1] ;
		
		//dp[i] = bs( i, posCarg ) ;
		//dp[i] = inf ;
		/*for( int j=i, tmp=0; j<=posCarg; j++ ) {
			tmp = max( tmp, arr[j][0] ) ;
			dp[i] = min( dp[i], tmp+dp[j+1] ) ;
		}
		printf("%d -----> %d\n", i, posCarg ) ;
		for( int j=i; j<=posCarg; j++ ) 
			printf("%d %d -> %d\n", subSec.carg(j), dp[j+1], subSec.carg(j)+ dp[j+1] ) ;
		printf("%d\n", dp[i] ) ;
		printf("-----\n" ) ;*/
		
	}
	
	printf("%d\n", dp[1] ) ;
	
	return 0 ;
}
