#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std ;
#define lim 100000

bool comp[lim] ;
queue <int> Q ;
int minP[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;
}

int caso() {
    int ini, fin ;
    scanf("%d%d", &ini, &fin ) ;
    memset( minP, 0, sizeof(minP) ) ;

    minP[ini] = 1 ;
    Q.push(ini) ;
    while( !Q.empty() ) {
        int pos = Q.front() ;
        Q.pop() ;
        for( int pot=10; pot<=10000; pot*=10 ) {
            for( int dig=0; dig<=9; dig++ ) {
                int pos2 = pos - ((pos%pot)/(pot/10))*(pot/10) ;
                pos2 += dig*(pot/10) ;

                if( pos2>=1000 && pos2<=9999 && !comp[pos2] && !minP[pos2] ) {
                    minP[pos2] = minP[pos]+1 ;
                    Q.push(pos2) ;
                }
            }
        }
    }

    return minP[fin] ;
}

int main() {
    int T ;
    criba() ;

    for( scanf("%d",&T); T; T-- )
        printf("%d\n", caso()-1 ) ;

    return 0 ;
}
