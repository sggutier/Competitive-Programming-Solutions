#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 15 ;
const int limB = 1<<lim ;
const int limN = 100 ;

int N ;
bool usd[limN][limB], res[limN][limB] ;
int arr[lim], cmb[limB] ;
int bts[limB] ;

bool memo( int R, int msk ) {
	if( usd[R][msk]==1 )
		return res[R][msk] ;
	if( bts[msk]!=-1 ) {
		//printf("->>> %d %d %d -> %d -> %d\n", R, cmb[msk]/R, cmb[msk], msk, arr[ bts[msk] ]%R==0 ) ;
		//getchar() ;
		usd[R][msk] = 1 ;
		return res[R][msk] = (arr[ bts[msk] ]%R==0) ;
	}

	int C = cmb[msk]/R ;
	usd[R][msk] = 1 ;

	if( R>C )
		return res[R][msk] = memo( C, msk ) ;

	int tmp[lim], W=0 ;
	int x, y ;

	for( int i=0; i<N; i++ )
		if( (1<<i) & msk )
			tmp[W++] = i ;

	for( int b=0; b<(1<<W); b++ ) {
		x = 0, y=0 ;
		for( int i=0; i<W; i++ )  {
			if( (1<<i) & b ) 
				x += (1<<tmp[i]) ;
			else 
				y += (1<<tmp[i]) ;
		}
		if( x==0 || y==0 )
			continue ;
		if( cmb[x]%R==0 && cmb[y]%R==0 && memo(R,x) && memo(R,y)  )
			return  res[R][msk] = 1 ;
		if( cmb[x]%C==0 && cmb[y]%C==0 && memo(C,x) && memo(C,y)  )
			return  res[R][msk] = 1 ;
	}
		//printf("%d %d -> %d -> %d\n", R, cmb[msk]/R, msk, res[R][msk] ) ;
		//getchar() ;

	return res[R][msk] = 0 ;
}

void caso(int T) {
	memset( usd, 0, sizeof(usd) ) ;
	memset( arr, 0, sizeof(arr) ) ;
	memset( cmb, 0, sizeof(cmb) ) ;
	memset( bts, 0, sizeof(bts) ) ;

	int R, C ;
	int W = 0 ;

	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}

	for( int i=0; i<(1<<N); i++ ) {
		bts[i] = -1 ;
		for( int j=0; j<N; j++ ) 
			if( (1<<j) & i )
				cmb[i] += arr[j] ;
	}
	for( int i=0; i<N; i++ )
		bts[1<<i] = i ;

	if( cmb[(1<<N)-1]%R==0 )
		W = memo(R,(1<<N)-1 ) ;

	printf("Case %d: %s\n", T, W? "Yes" : "No" ) ;

}

int main() {
	int T = 1 ;

	scanf("%d", &N ) ;
	while( N!=0 ) {
		caso(T++) ;
		scanf("%d", &N ) ;
	}

	return 0 ;
}


