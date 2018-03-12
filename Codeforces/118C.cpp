#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	int N, K ;
	string S, cpy ;
	int resI = (1<<30) ;
	string resS ;
	
	scanf("%d%d", &N, &K ) ;
	cin >> S ;
	
	for( int d=0; d<=9; d++ ) {
		cpy = S ;
		int chgd = K, cost=0 ;
		
		for( int i=0; i<N && chgd; i++ ) 
			if( cpy[i] == '0'+d   )
				chgd -- ;
		for( int dif=1; dif<=9; dif++  )  {
			if( d+dif<=9 )   {
				for( int i=0; i<N && chgd; i++ )  {
					if( cpy[i] == '0'+d+dif  )   {
						chgd -- ;
						cpy[i] = '0'+d ;
						cost += dif ;
					}
				}
			}
			if( d-dif>=0 )   {
				for( int i=N-1; i>=0 && chgd; i-- )  {
					if( cpy[i] == '0'+d-dif  )   {
						chgd -- ;
						cpy[i] = '0'+d ;
						cost += dif ;
					}
				}
			}
		}
		
		if( cost<resI  )  {
			resI = cost ;
			resS = cpy ;
		}
		else if( cost==resI ) 
			resS = min( resS, cpy ) ;
	}
	
	cout << resI << endl ;
	cout << resS << endl ;
	
	return 0 ;
}
