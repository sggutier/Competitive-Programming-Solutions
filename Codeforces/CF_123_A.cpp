#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std ;

// La la la la la lala
// La la la la la la la la la la
int rep[300] ;

int main() {
	int N ;
	string S ;
	string res ;
	
	cin >> S ;
	N = S.size() ;
	res = S ;
	
	for( int i=0; i<N; i++ ) {
		rep[ S[i] ] ++ ;
		res[i] = 0 ;
	}
	for( int i=1; i<N; i++ ) {
		int W ;
		for( W=2; W<=i && (i+1)%W; W++ ) ;
		if( W!=i+1 )
			continue ;
		if( !res[i] ) {			
			W = 0 ;
			for( int j=i; j<N; j+=(i+1)   )   {
				if( res[j] ) {
					W = res[j] ;
					break ;
				}
			}
			if( !W ) {
				W = 'a' ;
				for( int j='b'; j<='z'; j++ ) {
					if( rep[j] > rep[W] )
						W = j ;
				}
			}
		}
		else {
			W = res[i] ;
		}
		for( int j=i; j<N; j+=(i+1)   )   {
			if( !res[j]  )  {
				if( rep[ W ]  ) {
					rep[ W ] -- ;
					res[j] = W ;
				}
				else {
					printf("NO\n" ) ;
					return 0 ;
				}
			}
			else {
				if( W!=res[j] ) {
					printf("NO\n" ) ;
					return 0 ;
				}
			}
		}
	}
	if( 1 ) {
		int W = 'a' ;
		for( int j='b'; j<='z'; j++ ) {
			if( rep[j] > rep[W] )
				W = j ;
		}
		res[0] = W ;
	}
	cout << "YES" << endl ;
	cout << res << endl ;
	
	return 0 ;
}
