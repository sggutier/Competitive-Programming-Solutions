#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
typedef long long ll ;

int main() {
	ll N ;
	ll res=0LL, rep[9] ;
	int i, j ;
	// Fandango, zango zango zangare, zangare, que va pasando
	
	cin >> N ;
	
	for( i=0; i<9; i++ )
		rep[i] = 0LL ;
	for( i=0; i<9; i++ )
		rep[i] = N/9LL ;
	for( i=N%9; i; i-- )
		rep[i] ++ ;;
		
	for( i=0; i<9; i++ ) 
		for( j=0; j<9; j++ ) 
			res += rep[i]*rep[j]*rep[ (i*j)%9 ] ;
			
	for( i=1; i<=N; i++ ) {
		res -= N/i ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
