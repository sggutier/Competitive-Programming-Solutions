#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
using namespace std ;
#define par pair<long long,long long>
#define x first
#define y second
#define lim 8

long long manh( par A, par B ) {
    return abs(A.x-B.x) + abs(A.y-B.y) ;
}

int N = lim ;
par coor[lim] ;
long long dis[lim][lim], minP[lim] ;
priority_queue <par> Q ;

int main() {

    for( int i=0; i<N; i++ )
        cin >> coor[i].x >> coor[i].y ;

    for( int i=0; i<N; i++ ) {
        minP[i] = (1LL<<45) ;
        for( int j=0; j<N; j++ )
            dis[i][j] = manh( coor[i], coor[j] ) ;
    }
    for( int i=2; i<N; i+=2 ) {
        dis[i][i+1] = 10 ;
        dis[i+1][i] = 10 ;
    }

    minP[0] = 1LL ;
    Q.push( par(-1LL,0LL)  ) ;
    while( !Q.empty()  )  {
        par pos = Q.top() ;
        Q.pop() ;
        if( minP[pos.y]!=-pos.x  )
            continue ;

        for( int i=0; i<N; i++ ) {
            if( minP[i] > dis[pos.y][i]-pos.x   )  {
                minP[i] = dis[pos.y][i]-pos.x ;
                Q.push( par(-minP[i],i)   )  ;
            }
        }
    }

    cout << minP[1]-1LL << endl ;

    return 0 ;
}
