#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std ;
#define lim 100005

int N, N2, R ;
int arr[lim], usd[lim] ;
int dian[lim], dian2[lim] ;

void genera() {
    srand( time(NULL) ) ;
    for( int i=0; i<N2; i++ ) {
        arr[i] = rand()%(N2-i) ;
        for( int j=0; ; j++ ) {
            if( !usd[j] ) {
                arr[i] -- ;
                if( arr[i]<0 ) {
                    arr[i] = j ;
                    break ;
                }
            }
        }
        usd[arr[i]] = 1 ;
    }
}

int main() {
    int res=(1<<30), posRes ;

    scanf("%d%d", &N, &R ) ;
    N2 = N*2 ;
    /*for( int i=0; i<N2; i++ ) {
        scanf("%d", &arr[i] ) ;
        arr[i] -- ;
    }*/
    genera() ;

    for( int i=0; i<N2; i++ )
        printf("%d ", arr[i]+1 ) ;
    cout << endl ;

    for( int i=0; i<N; i++ ) {
        int W ;

        for( int j=0; j<N2; j++ )
            dian[j] = arr[j] ;
        for( int j=0; j<2*i; j++ )
            swap( dian[j], dian[j+1] ) ;
        /*for( int j=0; j<N2; j++ )
            printf("%d ", dian[j]+1 ) ;
        cout << endl ;*/

        for( int j=min(N2,R); j>0; j-- ) {
            int tmp ;
            if( dian[0]<dian[1] )
                swap( dian[0], dian[1] ) ;
            for( int k=1; k<N; k++ ) {
                if( dian[k*2]>dian[k*2+1] )
                    swap( dian[k*2], dian[k*2+1] ) ;
            }
            tmp = dian[0] ;
            for( int k=0; k+1<N; k++ ) {
                dian[k*2] = dian[(k+1)*2] ;
            }
            dian[N2-2] = tmp ;
            /*printf("     " ) ;
            for( int moo=0; moo<N2; moo++ )
                printf("%d ", dian[moo]+1 ) ;
            cout << endl ;*/
        }

        if( arr[0]==1 || arr[0]>=N ) {
            for( int j=0; j<N2; j++ ) {
                if( dian[j]==arr[0] ) {
                    W = j ;
                    break ;
                }
            }
        }
        else {
            for( int j=0; j<N2; j++ ) {
                if( dian[j]==arr[0] ) {
                    W = (j+N-((R-N2)%N) ) %N  ;
                    break ;
                }
            }
        }


        cout << i+1 << " " << W/2+1 << endl ;
        if( res>=W ) {
            res = W ;
            posRes = 2*i ;
        }
    }

    return 0 ;
}
