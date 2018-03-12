#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std ;
#define lim 1005

int amigos[lim][lim] ;

int main() {
    int N, D, W=0 ;
    int a[lim], b[lim], t[lim] ;
    map <string,int> ref ;
    string mir[lim*4] ;
    int R = 0 ;

    //Leer
    scanf("%d%d", &N, &D ) ;
    for( int i=0; i<N; i++ ) {
        string A, B ;

        cin >> A >> B >> t[i] ;

        if( ref.find(A)==ref.end() ) {
            mir[W] = A ;
            ref[A] = W++ ;
        }
        if( ref.find(B)==ref.end() ) {
            mir[W] = B ;
            ref[B] = W++ ;
        }
        a[i] = ref[A] ;
        b[i] = ref[B] ;
    }

    //Para cada mensaje mandado se busca algun mensaje similar
    //Que tenga una distancia menor a d y se marca el par de amigos
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<i; j++ ) {
            if( a[i]==b[j] && b[i]==a[j] && t[i]-t[j]<=D && t[i]!=t[j] ) {
                amigos[a[i]][b[i]] = 1 ;
                amigos[b[i]][a[i]] = 1 ;
            }
        }
    }

    //Imprimir
    for( int i=0; i<N; i++ ) {
        for( int j=i+1; j<N; j++ ) {
            if( amigos[i][j] )
                R ++ ;
        }
    }

    cout << R << endl ;
    for( int i=0; i<N; i++ )
        for( int j=i+1; j<N; j++ )
            if( amigos[i][j] )
                cout << mir[i] << " " << mir[j] << endl ;

    return 0 ;
}
