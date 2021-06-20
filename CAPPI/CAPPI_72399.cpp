#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000005

int N ;
int arr[lim] ;
int C ;
int carg[lim] ;

bool sePuede( int W ) {
	
	C = 0 ;
	for( int i=0; i<N; i++ ) {
		if( arr[i]<=W  ) 
			continue ;
		if( C && arr[i]==carg[C-1]   )    
			C -- ;
		else
			carg[C++] = arr[i] ;
	}	
	
	return C==0 ;
}

int main() {
	int ini=0, fin=(1<<30), piv ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
	
	while( ini<fin ) {
		piv = (ini+fin)/2LL ;
		if( sePuede(piv)  )  
			fin = piv ;
		else
			ini = piv+1LL ;
	}
	
	cout << ini << endl ;
	
	
	return 0 ;
}
