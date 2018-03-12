#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 300005 ;

struct trio {
    int a, b, c ;
    trio() {
    }
    trio( int &x, int &y, int &z ) {
        a = x ;
        b = y ;
        c = z ;
    }
};

bool operator<( trio A, trio B ) {
    return A.c < B.c ;
}

int N, E ;
trio arr[lim] ;
int padre[lim], prof[lim] ;

int raiz( int pos ) {
    while( padre[pos]!=pos )
        pos = padre[pos] ;
    return pos ;
}

void une( int A, int B ) {
    A = raiz(A) ;
    B = raiz(B) ;
    if( prof[A]>prof[B] )
        swap( A, B ) ;
    prof[B] = max( prof[B], prof[A]+1 ) ;
    padre[A] = B ;
}

int main() {
    int res = 0 ;

    scanf("%d%d", &N, &E ) ;
    for( int i=0; i<E; i++ ) {
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c ) ;
    }
    sort( arr, arr+E ) ;
    for( int i=1; i<=N; i++ )
        padre[i] = i ;

    for( int i=0; i<E; i++ ) {
        if( raiz(arr[i].a)==raiz(arr[i].b) )
            continue ;
        res += arr[i].c ;
        une( arr[i].a, arr[i].b ) ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
