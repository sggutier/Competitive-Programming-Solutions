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
    int W ;

    for( i=0; i<lim; i++ ) {
        for( j=0; j<lim; j++ )
            minT[i][j] = inf,  numC[i][j] = 0LL ;
        minT[i][i] = 0LL ;
        numC[i][i] = 1LL ;
    }

    scanf("%d%d",&N,&M ) ;
    cin >> W ;
    W -- ;
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
        /*for( i=0; i<N; i++ ) {
            for( j=0; j<N; j++ ) {
                cout << minT[i][j] << " " ;
            }
            cout << endl ;
        }
        printf("-------\n");*/
        for( i=0; i<N; i++ ) {
            if( i==k )
                continue ;
            for( j=0; j<N; j++ ) {
                if( j==k )
                    continue ;
                if( i==j )
                    continue ;
                if(  minT[i][k] + minT[k][j]  <  minT[i][j]  )  {
                    minT[i][j] = minT[i][k] + minT[k][j] ;
                    numC[i][j] = numC[i][k] * numC[k][j] ;
                    divP[i][j] = k ;
                }
                else if(  minT[i][k] + minT[k][j]  ==  minT[i][j]  )  {
                    //numC[i][j] += numC[i][k] * numC[k][j] ;
                }
            }
        }
    }

    M = 1 ;
    while( M ) {
        i = 0 ;
        j = W ;
        if(  minT[i][j] != inf )  {
            cout << minT[i][j] << " " ;
            cout << numC[i][j] << endl ;
        }
        else {
            cout << minT[i][j] << " " ;
            cout << numC[i][j] << endl ;
        }
        M -- ;
    }

    return 0 ;
}

