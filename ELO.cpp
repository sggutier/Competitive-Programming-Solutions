#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <list>
#include <utility>
using namespace std ;
#define par pair<double,int>
#define f first
#define s second
const int lim = 1000006 ;

int N, sP, E ;
list <par> adj[lim] ;
bool usd[lim] ;
double rat[lim] ;
queue <int> Q ;

double orgRat( double A, double B ) ;

int main() {
    scanf("%d%d%d", &N, &sP, &E ) ;
    for( int i=0; i<sP; i++ ) {
        int a ;
        double b ;
        scanf("%d%lf", &a, &b ) ;
        rat[a] = b ;
        usd[a] = 1 ;
        Q.push(a) ;
    }
    for( int i=0; i<E; i++ ) {
        int a, b ;
        double c ;
        scanf("%d%d%lf", &a, &b, &c ) ;
        adj[a].push_back( par(1-c,b) ) ;
        adj[b].push_back( par(  c,a) ) ;
    }

    while( !Q.empty() ) {
        int pos = Q.front() ;
        Q.pop() ;
        for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
            if( usd[it->s] )
                continue ;
            rat[it->s] = orgRat( rat[pos], it->f ) ;
            Q.push(it->s) ;
            usd[it->s] = 1 ;
        }
    }

    for( int i=0; i<N; i++ ) {
        printf("%.9lf\n", rat[i] ) ;
    }

    return 0 ;
}

double orgRat( double A, double B ) {
    return A - 400*log10( (1-B)/B ) ;
}
