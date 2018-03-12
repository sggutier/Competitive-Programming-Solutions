#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define lim 20

int N ;
int arr[lim] ;
int W=0 ;
int quak[lim] ;
int res = 0 ;

bool prueba( int sum, int pos, int carga ) {
	if( carga==sum ) 
		return 1 ;
	//printf("%d %d\n", sum, carga ) ;
	if( pos==-1 || carga>sum )
		return 0 ;
	return prueba(sum, pos-1, carga+quak[pos] ) || prueba(sum, pos-1, carga )    ;
}

void busca( int pos, int carga ) {
	//printf("%d %d -> ",pos, carga ) ;
	//for( int i=0; i<W; i++ )
	//rintf("%d ", quak[i] ) ;
	//intf("\n" ) ;
	if( pos==N ) {
		if( W>1 && carga%2==0 && prueba(carga/2,W-1,0)  )
			res ++ ;
		return ;
	}
	busca( pos+1, carga ) ;
	quak[W++] = arr[pos] ;
	busca( pos+1, carga+arr[pos] ) ;
	W -- ;
}

int main() {
	freopen( "subsets.in", "r", stdin ) ;
	freopen( "subsets.out", "w", stdout ) ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	sort( arr, arr+N ) ;
	busca( 0, 0 ) ;
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
