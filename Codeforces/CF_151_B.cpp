#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 1000

int tip( string A ) {
    int arr[6] ;
    int i ;

    arr[0] = A[0] ;
    arr[1] = A[1] ;
    arr[2] = A[3] ;
    arr[3] = A[4] ;
    arr[4] = A[6] ;
    arr[5] = A[7] ;

    for( i=1; i<6 && arr[i]==arr[i-1]; i++ ) ;
    if( i==6 )
        return 0 ;

    for( i=1; i<6 && arr[i]<arr[i-1]; i++ ) ;
    if( i==6 )
        return 1 ;
    return 2 ;
}

int main() {
    int F ;
    string nom[lim], res[3] ;
    int num[lim][3], mx[3] = {0,0,0} ;

    res[0] = "If you want to call a taxi, you should call: " ;
    res[1] = "If you want to order a pizza, you should call: " ;
    res[2] = "If you want to go to a cafe with a wonderful girl, you should call: " ;

    scanf("%d", &F ) ;
    for( int i=0; i<F; i++ ) {
        int N ;
        string tmp ;
        cin >> N >> nom[i] ;
        num[i][0] = 0 ;
        num[i][1] = 0 ;
        num[i][2] = 0 ;
        for( int j=0; j<N; j++ ) {
            cin >> tmp ;
            num[i][tip(tmp)] ++ ;
        }
        for( int j=0; j<3; j++ ) {
            mx[j] = max( mx[j], num[i][j] ) ;
        }
    }

    for( int j=0; j<3; j++ ) {
        int cnt = 0 ;
        cout << res[j] ;
        for( int i=0; i<F; i++ ) {
            if( num[i][j]==mx[j] ) {
                if( cnt )
                    printf(", " ) ;
                cnt ++ ;
                cout << nom[i] ;
            }
        }
        printf(".\n" ) ;
    }

    return 0 ;
}
