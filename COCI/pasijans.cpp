#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <list>
#include <utility>
#include <vector>
#include <queue>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
#define lim 1003
#define lim2 1000006


struct cola {
    int ini, fin ;
    par arr[lim] ;
    cola() {
        ini = 0 ;
        fin = 0 ;
    }
    void push( par W ) {
        arr[fin] = W ;
        fin = (fin+1)%lim ;
    }
    void pop() {
        ini = (ini+1)%lim ;
    }
    bool empty() {
        return ini==fin ;
    }
    par front() {
        return arr[ini] ;
    }
};



cola Q ;
priority_queue <par> res ;
map < int, list<int> > buk ;
int N, ord[lim], tam[lim], kk[lim] ;
vector <int> arr[lim] ;

void ordena( int ini, int fin, int col ) ;


int main() {
    int maxL = 0 ;
    par pos ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &tam[i] ) ;
        for( int j=0, a; j<tam[i]; j++ ) {
            scanf("%d", &a ) ;
            arr[i].push_back(a) ;
        }
        ord[i] = i ;
        maxL = max( maxL, tam[i] ) ;
    }

    Q.push( par(0,N-1) ) ;
    for( int col=0; col<maxL;  col++   ) {
        do {
            pos = Q.front() ;
            Q.pop() ;
            ordena( pos.f, pos.s, col ) ;
        } while( !Q.empty() && Q.front().f!=0 ) ;
    }

    for( int i=0; i<N; i++ ) {
        res.push( par( -arr[ ord[i] ][0], -i )   ) ;
    }

    while( !res.empty() ) {
        pos = res.top() ;
        pos.f *= -1 ;
        pos.s *= -1 ;
        res.pop() ;

        printf("%d ", pos.f ) ;

        kk[ord[pos.s]] ++ ;
        if( kk[ ord[pos.s] ] < tam[ord[pos.s]] )
            res.push( par( -arr[ ord[pos.s] ][ kk[ord[pos.s]] ], -pos.s )  );
    }
    printf("\n" ) ;

    return 0 ;
}

void ordena( int ini, int fin, int col ) {
    int a, W=ini ;

    buk.clear() ;

    for( int i=ini; i<=fin; i++ ) {
        if( tam[ ord[i] ]<=col )
            a = (1<<30) ;
        else
            a = arr[ ord[i] ][col] ;

        if( buk.find(a)==buk.end() )
            buk[a] = list<int>() ;
        buk[a].push_back( ord[i] ) ;
    }

    for( map<int, list<int> > :: iterator itBuk=buk.begin(); itBuk!=buk.end(); itBuk++ ) {
        a = W ;
        for( list<int>::iterator it=(*itBuk).s.begin();  it!=(*itBuk).s.end();   it++  ) {
            ord[W++] = (*it) ;
        }
        Q.push( par(a,W-1)  ) ;
    }
}
