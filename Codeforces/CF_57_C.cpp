#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 200704
#define mod 1000000007LL

int nP ; 
int P[20000] ;
int u[lim+1] ;
int pot[20000] ;

void criba() {
	int N, i, j ;
	nP = 0 ;
	P[ nP++ ]  =  2 ;
	for( i=3; i*i<=lim;  i+=2  )  {
		if( u[i] )
			continue ;
		u[i] = nP ;
		P[nP++] = i ;
		for( j=i*i;  j<=lim;  j+=2*i )
			u[j] = 1 ;
	}
	for( ; i<=lim;  i+=2  )  {
		if( !u[i] ) {
			u[i] = nP ;
			P[nP++] = i ;
		}
	}
}

void desc(  int  N,  int V  ) {
	int W = N ;
	for( int i=0;  P[i]*P[i]<=N;  i++  )   {
		while(  W%P[i]==0  )  {
			W /= P[i] ;
			pot[i] += V ;
		}
	}
	if( W>1 )
		pot[ u[W] ] += V ;
}

long long comb(  int N,  int K  )  {
	K = min( K, N-K ) ;
	int i ;
	long long res = 1LL ;
	for( i=1; i<=K; i++ )
		desc( i, -1 ) ;
	for( i=N-K+1; i<=N; i++ )
		desc( i, 1 ) ;
	for( i=0; i<nP; i++ ) {
		for( ; pot[i]; pot[i]-- )
			res = (res*P[i]) % mod ;
	}
	return res ;
}

int main() {
	criba() ;
	int N ;
	
	
	scanf("%d",&N ) ;
	
	
	cout << ( 2LL*comb( 2*N-1, N )  +  mod - N ) % mod << endl ;
	

	return 0 ;
}
