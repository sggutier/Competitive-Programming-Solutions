#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std ;
#define f first
#define s second

int N, W ;
pair < int, string > L[100] ;
int tam[100] ;
string arc[100][100] ;

int comp( int id ) {

    for( int i=0, j=0; i<N; i++ ) {
        for( ; j<tam[id] && arc[id][j]!=L[i].s; j++ ) ;
        if( j==tam[id] )
            return -1 ;
        j ++ ;
    }

    int res = (N*(N-1))/2 +1 ;
    for( int i=0; i<N; i++ )
        for( int j=i+1; j<N; j++ )
            if( L[i].f > L[j].f )
                res -- ;

    return res ;
}

int main() {
    int rId, rQt=-1 ;

    cin >> N ;
    for( int i=0; i<N; i++ ) {
        cin >> L[i].s ;
        L[i].f = i ;
    }
    cin >> W ;
    for( int i=0; i<W; i++ ) {
        cin >> tam[i] ;
        for( int j=0; j<tam[i]; j++ )
            cin >> arc[i][j] ;
    }

    do {
        for( int i=0; i<W; i++ ) {
            int tmp = comp(i) ;
            if( tmp>=0 && tmp>rQt ) {
                rQt = tmp ;
                rId = i ;
            }
            else if( tmp>=0 && tmp==rQt && i<rId ) {
                rId = i ;
            }
        }
    }while( next_permutation( L, L+N ) ) ;

    if( rQt==-1 ) {
        cout << "Brand new problem!" << endl ;
        return 0 ;
    }

    cout << rId+1 << endl ;
    cout << "[:" ;
    for( int i=0; i<rQt; i++ )
        cout << "|" ;
    cout << ":]" << endl ;

    return 0 ;
}
