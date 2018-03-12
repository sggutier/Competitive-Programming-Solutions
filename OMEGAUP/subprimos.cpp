#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 100005 ;

bool comp[lim] ;
int P, primos[lim] ;
int numDiv[lim], maxD[lim] ;

void criba() {
    P = 0 ;
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = i ;
    comp[0] = 1 ;
    comp[1] = 1 ;

    for( int i=2; i<lim; i++ )
        if( !comp[i] )
            primos[P++] = i ;
}

int main() {
    criba() ;

    maxD[1] = 0 ;
    numDiv[1] = 0 ;
    for( int i=1; i<lim; i++ ) {
        if(  ((long long) i)*primos[ maxD[i] ] > lim   )
            continue ;
        for( int j=maxD[i]; i*primos[j]<lim; j++ ) {
            maxD[i*primos[j]] = j ;
            numDiv[i*primos[j]] = numDiv[i] +1 ;
        }
    }

    int A, B, res=0 ;

    scanf("%d%d", &A, &B ) ;
    for( int i=A; i<=B; i++ )
        res += !(comp[numDiv[i]]) ;

    printf("%d\n", res ) ;

    return 0 ;
}
