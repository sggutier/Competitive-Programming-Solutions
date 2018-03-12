#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 1000006 ;

bool comp[lim] ;
int P = 0 ;
int primo[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;
    for( int i=2; i<lim; i++ )
        if( !comp[i] ) 
            primo[P++] = i ;
}

void caso( int N ) {
    for( int i=0; primo[i]<P; i++ ) {
        if( !comp[N-primo[i]] ) {
            printf("%d = %d + %d\n", N, primo[i], N-primo[i] ) ;
            return ;
        }
    }
    printf("Goldbach's conjecture is wrong.\n" ) ;
    return ;
}
	

int main() {
    int n ;
    criba() ;

    while( scanf("%d",&n)!=EOF && n )
        caso(n) ;
    
    return 0 ;
}
