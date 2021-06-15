#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 200

int main() {
	int N, M ;
	char mapa[lim][lim] ;
	int ini[lim], fin[lim] ;
	int res = 0 ;
	
	scanf("%d%d", &N, &M ) ;
	for( int i=0; i<N; i++ )
		scanf("%s", mapa[i] ) ;
		
	for( int i=0; i<N; i++ ) {
		ini[i] = -1 ;
		fin[i] = -1 ;
		for( int j=0; j<M; j++ ) {
			if( mapa[i][j] == 'W'   )	{
				ini[i] = j ;
				break ;
			}
		}
		for( int j=M-1; j>=0; j-- ) {
			if( mapa[i][j] == 'W'  )  {
				fin[i] = j ;
				break ;
			}
		}
	}
	
	while( N && ini[N-1]==-1   )   
		N -- ;
		
	for( int i=0, ant=0; i<N; i++ ) {
		if( ini[i] == -1 )
			continue ;
		if( i%2 ) {
			res += abs(ant - fin[i]) + (fin[i]-ini[i]) ;
			ant = ini[i] ;
		}
		else {
			res += abs(ant - ini[i]) + (fin[i]-ini[i]) ;
			ant = fin[i] ;
		}
	}
	res += max(N-1,0) ;
	
	printf("%d\n", res  ) ;
	
	return 0 ;
}
