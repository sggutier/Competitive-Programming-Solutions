#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std ;

int dir[1000] ;

int main() {
    string A, B ;
    int N, K ;

    cin >> N >> K ;
    cin >> A >> B ;

    for( int i=0; i<N; i++ )
        dir[i] = 1 ;
    N += K ;
    reverse( A.begin(), A.end() ) ;
    A += B ;
    cin >> K ;


    for( int w=0; w<K; w++ ) {
        for( int i=0; i+1<N; i++ ) {
            if( dir[i]==1 && dir[i+1]==0 ) {
                swap( dir[i], dir[i+1] ) ;
                swap( A[i], A[i+1] ) ;
                i ++ ;
            }
        }
    }

    cout << A << endl ;


    return 0 ;
}
