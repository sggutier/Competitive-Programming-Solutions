#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 300005

int N ;
int sig[lim], anc[lim] ;

int main() {
	
	scanf("%d", &N ) ;
	for( int i=1; i<=N; i++ ) {
		scanf("%d", &sig[i] ) ;
		if( sig[i] >= 0 && sig[i]<=N  )
			anc[ sig[i] ] ++ ;
	}
	
	for( int i=1; i<=N; i++ ) {
		if( sig[i] < 0 || sig[i] > N || anc[ sig[i] ] == 2  )  {
			int w = sig[i], pos, usd ;
			for( int j=0; j<=N; j++  ) {
				if( anc[j] == 0  &&  i!=j  ) {
					sig[i] = j ;
					for( int k=0; k<=N; k++  )  {
						if( anc[k] == 0 && k!=j  )   {
							pos = k ;
							usd = 0 ;
							while( pos )  {
								pos = sig[pos] ;
								usd ++ ;
							}
							if( usd==N ) {
								printf("%d %d\n", i, j ) ;
								return 0 ;
							}
						}
					}
				}
			}
			sig[i] = w ;
		}
	}
	
	printf("1 0\n" ) ;
	
	return 0 ;
}
