#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>
using namespace std ;
#define f first
#define s second
#define par pair<int,int>
#define lim 100
#define inf (1LL<<60)

long long minT[lim][lim] ;
long long numC[lim][lim] ;
int divP[lim][lim] ;
int W ;
int res[2*lim] ;

void imp( int ini, int fin ) {
    if(  divP[ini][fin] == ini  ||  divP[ini][fin]==fin  )  {
        res[W++] = fin ;
        return ;
    }
    imp( ini, divP[ini][fin]  ) ;
    imp( divP[ini][fin], fin  ) ;
}

int main() {

    int N, M ;
    int i, j, k ;
    long long w ;

    for( i=0; i<lim; i++ ) {
        for( j=0; j<lim; j++ )
            minT[i][j] = inf,  numC[i][j] = 0LL ;
    }

    scanf("%d%d",&N,&M ) ;
    while( M ) {
        scanf("%d%d",&i,&j ) ;
        cin >> w ;
        i--, j-- ;
        if(  minT[i][j] > w  )  {
            minT[i][j] = w ;
            minT[j][i] = w ;
            numC[i][j] = 1LL ;
            numC[j][i] = 1LL ;
            divP[i][j] = i ;
            divP[j][i] = i ;
        }
        else {
            numC[i][j] ++ ;
            numC[j][i] ++ ;
        }
        M -- ;
    }

    for( k=0; k<N; k++ ) {
        for( i=0; i<N; i++ ) {
            if( i==k )
                continue ;
            for( j=0; j<N; j++ ) {
                if( j==k )
                    continue ;
                if( j==i )
                    continue ;
                if(  minT[i][k] + minT[k][j]  <  minT[i][j]  )  {
                    minT[i][j] = minT[i][k] + minT[k][j] ;
                    numC[i][j] = numC[i][k] * numC[k][j] ;
                    divP[i][j] = k ;
                }
                else if(  minT[i][k] + minT[k][j]  ==  minT[i][j]  )  {
                    numC[i][j] += numC[i][k] * numC[k][j] ;
                }
            }
        }
    }

    scanf("%d",&M ) ;
    while( M ) {
        scanf("%d%d",&i,&j ) ;
        i--, j-- ;
        if( numC[i][j] != 1 ) {
            cout << numC[i][j] << endl ;
        }
        else {
            W = 0 ;
            cout << minT[i][j] ;
            printf(" %d ",i+1 ) ;
            imp( i, j ) ;
            for( k=0; k<W; k++ )
                printf("%d ",res[k]+1 ) ;
            printf("\n");
        }
        M -- ;
    }

    return 0 ;
}

