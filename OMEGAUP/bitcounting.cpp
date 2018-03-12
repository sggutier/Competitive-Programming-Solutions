#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 64

long long pasc[lim][lim] ;
int dis[lim] ;

void prec() {
	
	for( int i=0; i<61; i++ ) {
		pasc[i][0] = 1LL ;
		pasc[i][i] = 1LL ;
		for( int j=1; j<i; j++ ) {
			pasc[i][j] = pasc[i-1][j] + pasc[i-1][j-1] ;
		}
	}
	
	dis[1] = 0 ;
	for( int i=2; i<lim; i++ ) {
		int b=0; 
		for( int j=0; j<10; j++ ) {
			if( (1<<j) & i )
				b ++ ;
		}
		dis[i] = dis[b]+1 ;
	}
}

long long rec( long long N, int carg, int pos, int X ) {
	if( pos==-1 ) {
		if( dis[carg]+1==X )
			return 1LL ;
		return 0LL ;
	}
	
	if( (1LL<<pos) & N  ) {
		long long res=0LL ;
		for( int i=0; i<=pos; i++ ) {
			if( i+carg<=0 || dis[i+carg]+1!=X )
				continue ;
			res += pasc[pos][i] ;
		}
		return res + rec(N,carg+1,pos-1,X) ;
	}
	
	return rec( N, carg, pos-1, X ) ;
}

int main() {
	prec() ;
	
	int i ;
	long long A, B, X ;
	long long res=0LL ;
	
	cin >> A >> B >> X ;
	
	if( X==0LL ) {
		if( A==1LL )
			cout << 1LL << endl ;
		else
			cout << 0 << endl ;
		return 0 ;
	}
	
	if( A>B )
		swap( A, B ) ;
	
	A -- ;
	for( i=62; ((1LL<<i)&A) <= 0LL && i>=0; i-- ) ;
	res -= rec(A,0,i,X) ;
	for( i=62; ((1LL<<i)&B) <= 0LL && i>=0; i-- ) ;
	res += rec(B,0,i,X) ;
	
	cout << res << endl ;
	
	return 0 ;
}
