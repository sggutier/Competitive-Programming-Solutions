#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std ;
const int limN = 30 ;
const int limW = 60 ;
const int limT = 260 ;
const int limK = 460 ;
const int limK2 = limK*2 ;
const int inf = (1<<30) ;

int E ;
bool adj[limK2][limK2] ;
int W;
int minId[limK2] ;
stack <int> Q ;

int prueba( int pos ) {
    if( minId[pos] )
        return minId[pos] ;

    int K = W ;
    minId[pos] = W++ ;
    Q.push(pos) ;

    for( int i=0; i<limK2; i++ ) {
        if( adj[pos][i] )
            minId[pos] = min( minId[pos], prueba(i) ) ;
    }

    if( minId[pos]==K ) {
        int impl[limK2] ;
        int T = 0 ;

        do {
            impl[T++] = Q.top() ;
            Q.pop() ;
        } while( impl[T-1]!=pos ) ;

        for( int i=0; i<T; i++ ) {
            minId[ impl[i] ] = inf ;
            for( int j=0; j<T; j++ )
                adj[ impl[i] ][ impl[j] ] = 1 ;
        }
    }



    return minId[pos] ;
}

bool caso() {
    W = 1 ;
    memset( adj, 0, sizeof(adj) ) ;
    memset( minId, 0, sizeof(minId) ) ;

    scanf("%d", &E ) ;
    scanf("%d", &E ) ;
    scanf("%d", &E ) ;
    for( int i=0; i<E; i++ ) {
        int r, c, x, y ;
        int a, b ;
        scanf("%d%d%d%d", &r, &c, &x, &y ) ;
        r--, c--, x--, y-- ;
        a = (r<=x)*limK ;
        b = (c<=y)*limK + limN ;

        adj[ i+limW ][ r+a ] = 1 ;
        adj[ i+limW ][ y+b ] = 1 ;
        adj[ i+limT ][ x+a ] = 1 ;
        adj[ i+limT ][ c+b ] = 1 ;

        adj[ (r+a+limK)%limK2 ][ i+limW+limK ] = 1 ;
        adj[ (y+b+limK)%limK2 ][ i+limW+limK ] = 1 ;
        adj[ (x+a+limK)%limK2 ][ i+limT+limK ] = 1 ;
        adj[ (c+b+limK)%limK2 ][ i+limT+limK ] = 1 ;

        adj[ i+limW+limK ][ i+limT ] = 1 ;
        adj[ i+limT+limK ][ i+limW ] = 1 ;
    }

    for( int i=0; i<limK2; i++ ) {
        prueba( i ) ;

        if( adj[ i ][ (i+limK)%limK2 ]  )
            return 0 ;
    }

    return 1 ;
}


int main() {
    int N=1 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        printf("%s\n", caso()? "Yes": "No" ) ;

    return 0 ;
}
