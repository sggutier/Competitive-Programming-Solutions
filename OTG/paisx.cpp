#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <list>
using namespace std ;
#define lim 1000

struct arst {
    int u ;
    int w, t ;
    arst() {
    }
    arst(int X, int Y, int Z ) {
        u = X ;
        w = 0LL + Y ;
        t = 0LL + Z ;
    }
};

struct par {
    int f ;
    int s ;
    par() {
    }
    par( int A, int B ) {
        f = A+0LL, s= B ;
    }
};

bool operator<( par A, par B ) {
    return A.f > B.f ;
}

priority_queue <par> Q ;
list <arst>  adj[lim] ;
int minT[lim] ;
bool usd[lim] ;

int main() {
    int N, M ;
    arst tmp ;
    int i, j ;
    int A, B ;
    par pos, pos2 ;
    list <arst> :: iterator it ;

    scanf("%d%d",&N,&M ) ;
    while( M ) {
        M -- ;
        scanf("%d%d",&i,&tmp.u) ;
        cin >> tmp.w >> tmp.t  ;
        i--, tmp.u -- ;
        adj[i].push_back(tmp) ;
        adj[tmp.u].push_back(  arst(i,tmp.w,tmp.t)  )  ;
    }
    scanf("%d%d",&A,&B ) ;
    A--, B-- ;

    for( i=0; i<N; i++ )
        minT[i] = -1 ;
    minT[A] = 0 ;
    Q.push( par(0,A)  ) ;

    while( !Q.empty()  )  {
        pos = Q.top() ;
        Q.pop() ;
        if( usd[pos.s] )
            continue ;
        usd[pos.s] = 1 ;
        for( it=adj[pos.s].begin();  it!=adj[pos.s].end();  it++   )  {
            if( usd[(*it).u] )
                continue ;
            if(  minT[(*it).u] == -1   ||   minT[(*it).u] >  max( pos.f,(*it).t ) + (*it).w  )   {
                minT[(*it).u] = max( pos.f,(*it).t ) + (*it).w  ;
                Q.push(  par(minT[(*it).u],(*it).u)   ) ;
            }
        }
    }


    cout << minT[B] << endl ;

    return 0 ;
}
