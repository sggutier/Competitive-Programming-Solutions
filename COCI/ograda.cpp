#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 100005

int N ;
int dif[lim], arr[lim], res[lim] ;

int main() {
    int R = 0 ;
    int cnt[5] = { 0, 0, 0, 0, 0 } ;
    int i = 0 ;

    scanf("%d", &N ) ;
    for( int j=0; j<N; j++ )
        scanf("%d", &dif[j] ) ;
    for( int j=0; j<N; j++ )
        scanf("%d", &arr[j] ) ;
    sort( arr, arr+N ) ;

    i = 0 ;
    while( i+1<N ) {
        int j = i+1, tmp = 2 ;
        if( i==0 )
            tmp = 1 ;
        if( (dif[i+1]-dif[i])/abs(dif[i+1]-dif[i]) == 1 )
            tmp *= -1 ;
        cnt[ tmp+2 ] ++ ;
        while(  j<N  && (dif[j]-dif[j-1])/abs(dif[j]-dif[j-1]) ==  (dif[i+1]-dif[i])/abs(dif[i+1]-dif[i])   ) {
            j ++ ;
        }

        i = j-1 ;
    }
    if( 1 ) {
        i -- ;
        int j = i+1, tmp = 1 ;
        if( (dif[i+1]-dif[i])/abs(dif[i+1]-dif[i]) == -1 )
            tmp *= -1 ;
        cnt[ tmp+2 ] ++ ;
    }

    i = N-1 ;
    for( int k=2; k>=1; k-- ) {
        while( cnt[k+2] ) {
            cnt[k+2] -- ;
            R += arr[i--]*k ;
        }
    }
    i = 0 ;
    for( int k=-2; k<=-1; k++ ) {
        while( cnt[k+2] ) {
            cnt[k+2] -- ;
            R += arr[i++]*k ;
        }
    }

    cout << R << endl ;

    return 0 ;
}
