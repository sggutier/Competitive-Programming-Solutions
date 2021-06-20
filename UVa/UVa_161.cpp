#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std ;

int N = 0 ;
int nums[300] ;

int main() {
    N = 1 ;
    while( N ) {
	N = 0 ;
	while( scanf("%d", &nums[N++]) && nums[N-1]!=0 ) ;
	N -- ;
	if( !N )
	    return 0 ;
	int T = nums[0] ;
	do {
	    bool vald = 1 ;
	    for( int i=0; i<N; i++ ) {
		if( T%nums[i]>=nums[i]-5 || T%(2*nums[i])>=nums[i] ) {
		    vald = 0 ;
		    break ;
		}
	    }
	    if( vald )
		break ;
	    T ++ ;
	} while( T<=60*60*5 ) ;
	if( T>60*60*5 )
	    printf("Signals fail to synchronise in 5 hours\n" ) ;
	else
	    printf("%02d:%02d:%02d\n", T/(3600), (T/60)%60, T%60 ) ;
    }
    
    return 0 ;
}
