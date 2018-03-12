#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

long long rep[100][100] ;

int main() {
	int N ;
	string S ;
	int a,b,c,d ;
	long long i,j,k,l ;
	long long res = 0LL ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		cin >> S ;
		rep[S[0]-'A'][S[S.size()-1]-'A'] ++ ;
	}
	
	for( a=0; a<26; a++ ) {
		for( b=0; b<26; b++ ) {
			for( c=0; c<26; c++ ) {
				for( d=0; d<26; d++ ) {
					
					i = rep[a][b] ;
					rep[a][b] -- ;
					j = rep[a][c] ;
					rep[a][c] -- ;
					k = rep[c][d] ;
					rep[c][d] -- ;
					l = rep[b][d] ;
					rep[b][d] -- ;
					
					if( i>0LL && j>0LL && k>0LL && l>0LL ) {
						res += i*j*k*l ;
					}
					
					rep[a][b] ++ ;
					rep[a][c] ++ ;
					rep[c][d] ++ ;
					rep[b][d] ++ ;
					
				}
			}
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
