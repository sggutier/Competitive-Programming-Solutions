#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define lim 100005
#define f first
#define s second

struct BIT {
	int dat[lim] ;
	BIT () {
	}
	void mete( int pos, int nov ) {
		for( ; pos<lim; pos += (pos & -pos)   ) 
			dat[pos] += nov ;
	}
	int saca( int pos ) {
		int res = 0 ;
		for( ; pos>0; pos -= (pos & -pos)  )
			res += dat[pos] ;
		return res ;
	}
} ;

int N ;
par arr[lim] ;
int tmp[lim] ;
BIT des ;

int main() {
	long long res = 0LL ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i].f ) ; 
		arr[i].s = i ;
	}
	
	sort( arr, arr+N ) ;
	for( int i=0, j=1; i<N; i++ ) {
		if( i && arr[i].f!=arr[i-1].f )
			j ++ ;
		tmp[ arr[i].s ] = j ;
	}
		
	for( int i=N-1; i>=0; i-- ) {
		des.mete( tmp[i], 1 ) ;
		res += des.saca( tmp[i]-1 ) ;
	}
	
	printf("%lld\n", res ) ;
	
	return 0 ;
}


