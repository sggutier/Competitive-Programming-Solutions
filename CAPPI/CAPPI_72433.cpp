#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100003

int N, M ;
int dis[lim], reg[lim], mang[lim] ;

bool sePuede( int W ) {
    int prev = 0 ;

    for( int i=0; i<M && prev<N; i++ ) {
        int pos = prev,  carg=0, rec=0 ;

        carg += reg[pos] ;
        rec += dis[pos]-dis[prev] ;
        rec += min(  abs(dis[mang[i]]-dis[prev]),   abs(dis[mang[i]]-dis[pos])    )  ;

        while(  pos<N && carg+rec<=W  )  {
            pos ++ ;
            if( pos<N ) {
                carg += reg[pos] ;
                rec = dis[pos]-dis[prev] ;
                rec += min(  abs(dis[mang[i]]-dis[prev]),   abs(dis[mang[i]]-dis[pos])    )  ;
            }
        }

        prev = pos ;
    }

    return prev==N ;
}

int bs() {
    int ini, fin, piv ;
    ini = 1 ;
    fin = 400000000 ;

    while( ini<fin ) {
        piv = (ini+fin)/2 ;
        if(  sePuede(piv)   )
            fin = piv ;
        else
            ini = piv+1 ;
    }

    return ini ;
}


int main() {
    dis[0] = 0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=1; i<N; i++ ) {
        scanf("%d", &dis[i]) ;
        dis[i] += dis[i-1] ;
    }
    for( int i=0; i<N; i++ ) {
        scanf("%d", &reg[i] ) ;
    }
    for( int i=0; i<M; i++ ) {
        scanf("%d", &mang[i] ) ;
        mang[i] -- ;
    }

    printf("%d\n",  bs()   )  ;

    return 0 ;
}
