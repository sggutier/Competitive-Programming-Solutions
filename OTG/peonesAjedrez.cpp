#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int res[1001] ;
int W[1001] ;

void busca( int pos )   {
    if( res[pos]!=-2 )
        return  ;
    busca( pos-2 ) ;
    busca( pos-3 ) ;


    W[pos] = 0 ;
    res[pos] = -1 ;
    if(  W[pos-2] == 1  )  {
        W[pos] |= 2 ;
        res[pos] = 0 ;
    }
    if(  W[pos-2] == 2  )  {
        W[pos] |= 1 ;
    }
    if(  W[pos-3] == 1  )  {
        W[pos] |= 2 ;
        res[pos] = 1 ;
    }
    if(  W[pos-3] == 2  )  {
        W[pos] |= 1 ;
    }

    int a, b ;
    for( int i=pos-2; i>2; i-- )   {
        busca( i-2 ) ;
        busca( pos-i-1 ) ;
        a = W[i-2] ;
        b = W[pos-i-1] ;
        if( a==3 || b==3 )
            continue ;
        if( a!=b ) {
            W[pos] |= 1 ;
        }
        else {
            W[pos] |= 2 ;
            res[pos] = i-1 ;
        }
    }

    return ;
}

int main() {
    for( int i=1000; i; i-- )
        res[i] = -2 ;
    res[1] = 0 ;
    res[2] = 0 ;
    res[3] = 1 ;
    W[1] = 2 ;
    W[2] = 2 ;
    W[3] = 2 ;
    busca( 1000 ) ;

    int N, W ;

    /*scanf("%d",&N ) ;
    while( N ) {
		scanf("%d",&W ) ;
		printf("%d\n",res[W] ) ;
        N -- ;
    }*/
    N = 1000 ;
    while( N ) {
		printf("%d\n",res[N] ) ;
		N -- ;
	}

    return 0 ;
}
