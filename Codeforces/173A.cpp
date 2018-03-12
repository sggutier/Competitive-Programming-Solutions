#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int W, O=0 ;
    string A, B ;
    int X, Y ;
    int rL=0, rR=0 ;
    int i, j ;

    scanf("%d", &W ) ;
    cin >> A >> B ;
    X = A.size();
    Y = B.size() ;

    for( i=0; i<X; i++ ) {
        if( A[i]=='R' )
            A[i] = 0 ;
        else if( A[i]=='P' )
            A[i] = 1 ;
        else
            A[i] = 2 ;
    }
    for( i=0; i<Y; i++ ) {
        if( B[i]=='R' )
            B[i] = 0 ;
        else if( B[i]=='P' )
            B[i] = 1 ;
        else
            B[i] = 2 ;
    }

    i = 0 ;
    j = 0 ;
    do {
        if( (A[i]+1)%3==B[j] )
            rL ++ ;
        else if( A[i]!=B[j] )
            rR ++ ;
        i = (i+1)%X ;
        j = (j+1)%Y ;
        O ++ ;
    } while( i!=0 || j!=0 ) ;

    rL *= W/O ;
    rR *= W/O ;
    W %= O ;
    while( W ) {
        if( (A[i]+1)%3==B[j] )
            rL ++ ;
        else if( A[i]!=B[j] )
            rR ++ ;
        i = (i+1)%X ;
        j = (j+1)%Y ;
        W -- ;
    }

    printf("%d %d\n", rL, rR ) ;
}
