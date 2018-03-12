#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <cmath>
using namespace std ;
#define par pair<double,double>
#define f first
#define s second
#define lim 1005

int N ;
double coor[lim][2] ;
int F[lim], ord[lim][lim] ;
bool usd[lim] ;
double minP[lim] ;
priority_queue < par > Q ;

int main() {
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%lf%lf", &coor[i][0], &coor[i][1] ) ;
        scanf("%d", &F[i] ) ;
        for( int j=0; j+1<N; j++ ) {
            scanf("%d", &ord[i][j] ) ;
            ord[i][j] -- ;
        }
    }

    for( int i=0; i<N; i++ )
        minP[i] = -(1<<30)*1.0 ;

    minP[0] = -1.0 ;
    Q.push( par( -1.0, 0 )  ) ;
    while( !Q.empty() ) {
        int pos = Q.top().s ;
        Q.pop() ;
        if( usd[pos] )
            continue ;
        usd[pos] = 1 ;

        for( int i=0, w=0; i+1<N && w<F[pos]; i++ ) {
            if( usd[ord[pos][i]] )
                continue ;
            w ++ ;
            int j = ord[pos][i] ;
            double dis = minP[pos], a, b ;
            a = coor[pos][0] - coor[j][0] ;
            b = coor[pos][1] - coor[j][1] ;
            dis -= sqrt( a*a + b*b ) ;
            if( minP[j]<dis ) {
                minP[j] = dis ;
                Q.push( par(dis,j) ) ;
            }
        }
    }

    for( int i=0; i<N; i++ )
        printf("%lf\n", -minP[i]-1.0 ) ;

    return 0 ;
}
