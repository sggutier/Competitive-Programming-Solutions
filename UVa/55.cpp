#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std ;

void caso(int N ) {
	string arr[10] ;
	int res[10] ;
	memset( res, 0, sizeof(res)  )  ;
	
	for( int i=0; i<N; i++ ) {
		cin >> arr[i] ;
	}
	for( int i=0; i<N; i++ ) {
		string S ;
		int pos, w, q, dif, j ;
		
		cin >> S ;		
		for( pos=0; arr[pos]!=S;  pos++   ) ;
		scanf("%d%d", &w, &q ) ;
		if( !q )
			continue ;
		dif = w/q ;
		while( q ) {
			q -- ;
			cin >> S ;
			for( j=0; arr[j]!=S; j++ ) ;
			res[j] += dif ;
			res[pos] -= dif ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		cout << arr[i] << " " << res[i] << endl ;
	}
}

int main() {
	//freopen( "55.in", "r", stdin ) ;
	
	int N, t=0 ;
	while( scanf("%d", &N )  != EOF   )  {
		if( t )
			printf("\n" ) ;
		caso(N) ;
		t ++ ;
	}
	return 0 ;
}
