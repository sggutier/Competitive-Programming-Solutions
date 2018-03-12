#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define limP 400

int P ;
int primos[limP], comp[limP] ;
long long mod ;

void criba() {
	P = 0 ;
	for( int i=2; i*i<limP; i++ ) {
		if( comp[i] )
			continue ;
		for( int j=i*i; j<limP; j+=i )
			comp[j] = 1 ;
	}
	for( int i=2; i<limP; i++ ) {
		if( !comp[i] )
			primos[P++] = i ;
	}
}

long long calc( long long S, long long D, long long M ) {
	long long res = 0LL ;
	long long Q = (S/D)%S ;
	res += (M+1LL)*S ;
	res -= Q*(M+1LL) ;
	res +=  (   (Q*(Q+1LL))/2LL )*D  ;
	res -= ( S*(S+1LL) ) /2LL ;
	return res%mod ;
}

int main() {
	freopen( "banner.in", "r", stdin ) ;
	freopen( "banner.out", "w", stdout ) ;
	
	criba() ;
	
	long long N, M, L, H ;
	long long A, B, W, Q, T, len ;
	long long res = 0LL ;
	
	//scanf("%d%d%d%d%d",&N, &M, &L, &H, &mod ) ;
	cin >> N >> M >> L >> H >> mod ;
	
	A = min( H-1, N ) ;
	L -- ;
	for( long long i=1LL; i<=A; i++ ) {
		W = 1LL ;
		Q = i ;
		for( int j=0; j<P; j++ ) {
			if( Q%primos[j]==0 )
				W *= primos[j] ;
			while( Q%primos[j]==0 ) {
				Q /= primos[j] ;
			}
		}
		W *= Q ;
		
		T = 0LL ;
		len = (long long)( sqrt(H*H - i*i)  ) ;
		len = min( len, M ) ;
		//cout << "--------" << len << " " << W  ;
		T += calc( len, W, M ) ; ;
		if( i<=L ) {
			len = (long long)( sqrt(L*L - i*i)  ) ;
			len = min( len, M ) ;
			//cout << len ;
			T = (T+mod-calc( len, W, M ) )%mod ;
		}		
		//cout << endl ;
		
		//cout << i << " " << T << endl ;
		T = 2LL*T*(N+1LL-i) ;
		
		res = (res+T)%mod ;
	}
	
	if( L==0LL ) {
		res += N*(M+1LL) ;
		res += M*(N+1LL) ;
		res %= mod ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
