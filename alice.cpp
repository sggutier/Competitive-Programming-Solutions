#include <iostream>
using namespace std ;

long long alt( long long sPot, long long x ) {
	if( sPot>0LL ) {
		long long normX = x/sPot ;
		if( normX == 0LL ||  normX==4LL  ) 
			return 0LL ;
		else if( normX==1LL || normX==3LL ) 
			return sPot     + alt( sPot/5LL, x%sPot ) ;
		else 
			return sPot*2LL + alt( sPot/5LL, x%sPot ) ;
	}
	return 0LL ;
}

int main() {
	int N ;

	cin >> N ;

	for( int i=0; i<N; i++ ) {
		long long m, x, y, pot = 1LL ;

		cin >> m >> x >> y ;

		m -- ;
		for( int i=0; i<m; i++, pot*=5LL ) ;

		cout << ( (y < alt(pot,x) )? "crystal" : "empty" ) << endl ;
	}

	return 0 ;
}


