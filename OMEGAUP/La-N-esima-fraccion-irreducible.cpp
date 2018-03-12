#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second


int gcd( int a, int b ) {
    int c = 0 ;
    while( b ) {
	c = b ;
	b = a%b ;
	a = c ;
    }
    return a ;
}

bool compF( par A, par B ) {
    int d=A.s*B.s, a=A.f*(d/A.s), b=B.f*(d/B.s) ;
    return a<b ;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N, K, T=0 ;
    par *arr ;

    scanf("%d%d", &N, &K ) ;
    arr = new par[K*K] ;
    N -- ;


    for( int i=1; i<=K; i++ ) {
	for( int j=1; j<=i; j++ ) {
	    if( gcd(i,j)==1 )
		arr[T++] = par(j,i) ;
	}
    }

    sort( arr, arr+T, compF ) ;

    long long res = N%T, rep = N/T  ;
    printf("%lld/%d\n", rep*arr[res].s + arr[res].f, arr[res].s ) ;

    delete arr ;
    return 0 ; 
}

