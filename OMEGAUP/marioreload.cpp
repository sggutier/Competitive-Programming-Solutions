#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <list>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
const int limN = 100 ;
const int limK = 10 ;

int N, E, K ;
list <int> adj[limN] ;
list <int> tip[limK] ;
int req[limN], opc[limN] ;
int minP[limN][1<<limK] ;
queue <int> Q[2], Q2[2] ;

int main() {
    int act=0, sig=1 ;

    scanf("%d%d%d", &N, &E, &K ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d%d", &opc[i], &req[i] ) ;
        opc[i] = max( -1, opc[i]-1 ) ;
        req[i] = max( -1, req[i]-1 ) ;
        if( opc[i]!=-1 )
            tip[ opc[i] ].push_back(i) ;
    }
    for( int i=0; i<E; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        a--, b-- ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    Q[act].push(0) ;
    Q2[act].push(0) ;
    while( !Q[act].empty() ) {

        while( !Q[act].empty() ) {
            int pos=Q[act].front(), masc=Q2[act].front() ;
            Q[act].pop() ;
            Q2[act].pop() ;

            if( opc[pos]!=-1 && ((1<<opc[pos])&masc)==0  ) {
                for( list<int>::iterator it=tip[ opc[pos] ].begin();   it!=tip[ opc[pos] ].end();  it++  ) {
                    if(  minP[*it][masc | (1<<opc[pos])]  )
                        continue ;
                    minP[*it][masc | (1<<opc[pos])] = minP[pos][masc] ;
                    Q[act].push( *it ) ;
                    Q2[act].push(   masc | (1<<opc[pos])   ) ;
                }
            }

            if( req[pos]!=-1  &&  ((1<<req[pos])&masc)==0 )
                continue ;

            for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end();  it++  ) {
                if( minP[*it][masc] )
                    continue ;
                minP[*it][masc] = minP[pos][masc] +1 ;
                Q[sig].push( *it ) ;
                Q2[sig].push( masc ) ;
            }
        }

        swap( act, sig ) ;
    }

    printf("%d\n", minP[N-1][(1<<K)-1] ) ;

    return 0 ;
}
