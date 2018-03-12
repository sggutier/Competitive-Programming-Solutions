#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 105

int main() {
	int n, m, a,b,c ;
	int x, y ;
	char res[lim][lim] ;
	
	cin >> n >> m >> a >> b >> c ;
	
	if( n%2 && m%2 ) {
		cout << "IMPOSSIBLE" << endl ;
		return 0 ;
	}
	x = n ;
	y = m ;
	if( n%2 ) {
		if( a<m/2 ) {
			cout << "IMPOSSIBLE" << endl ;
			return 0 ;
		}
		n -- ;
		a -= m/2 ;
		for( int i=0; i<m; i+=2 ) {
			if( (i/2)%2 ) {
				res[n][i] = 'x' ;
				res[n][i+1] = 'x' ;
			}
			else {
				res[n][i] = 'y' ;
				res[n][i+1] = 'y' ;
			}
		}
	}
	if( m%2 ) {
		if( b<n/2 ) {
			cout << "IMPOSSIBLE" << endl ;
			return 0 ;
		}
		m -- ;
		b -= n/2 ;
		for( int i=0; i<n; i+=2 ) {
			if( (i/2)%2 ) {
				res[i][m] = 'x' ;
				res[i+1][m] = 'x' ;
			}
			else {
				res[i][m] = 'y' ;
				res[i+1][m] = 'y' ;
			}
		}
	}
	
	a -= a%2 ;
	b -= b%2 ;
	if( n*m > 4*c + b*2 + a*2 ) {
		cout << "IMPOSSIBLE" << endl ;
		return 0 ;
	}
	
	for( int i=0; i<n; i+=2 ) {
		for( int j=0; j<m; j+=2 ) {
			char k ;
			if( c ) {
				c -- ;
				for( k='a'; ; k++ ) {
					if(  i && (k==res[i-1][j] || k==res[i-1][j+1])    )
						continue ;
					if(  j && (k==res[i][j-1] || k==res[i+1][j-1])    )
						continue ;
					break ;
				}
				res[i+0][j+0] = k ;
				res[i+0][j+1] = k ;
				res[i+1][j+0] = k ;
				res[i+1][j+1] = k ;
			}
			else if( a ) {
				a-=2 ;
				for( k='a'; ; k++ ) {
					if(  i && (k==res[i-1][j] || k==res[i-1][j+1])    )
						continue ;
					if(  j && k==res[i][j-1]    )
						continue ;
					break ;
				}
				res[i+0][j+0] = k ;
				res[i+0][j+1] = k ;
				for( k='a'; ; k++ ) {
					if(  k==res[i][j] || k==res[i][j+1]    )
						continue ;
					if(  j && k==res[i+1][j-1]    )
						continue ;
					break ;
				}
				res[i+1][j+0] = k ;
				res[i+1][j+1] = k ;
			}
			else {
				b -=2 ;
				for( k='a'; ; k++ ) {
					if(  i && k==res[i-1][j]    )
						continue ;
					if(  j && (k==res[i][j-1] || k==res[i+1][j-1])    )
						continue ;
					break ;
				}
				res[i+0][j+0] = k ;
				res[i+1][j+0] = k ;
				for( k='a'; ; k++ ) {
					if(  i && k==res[i-1][j+1]    )
						continue ;
					if(  k==res[i][j] || k==res[i+1][j]    )
						continue ;
					break ;
				}
				res[i+0][j+1] = k ;
				res[i+1][j+1] = k ;
			}
		}
	}
	
	for( int i=0; i<x; i++ ) {
		for( int j=0; j<y; j++ ) 
			printf("%c", res[i][j] ) ;
		cout << endl ;
	}
	
	return 0 ;
}

