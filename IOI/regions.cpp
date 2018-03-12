#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <utility>
#include <cmath>
using namespace std ;
#define limN 200005
#define limR  25005
#define limN2 450
#define par pair<int,int>
#define f first
#define s second

struct pila {
    int tam ;
    int arr[limN] ;
    pila() {
        tam = 0 ;
    }
    bool empty() {
        return tam == 0 ;
    }
    int top() {
        return arr[tam-1] ;
    }
    void pop() {
        tam -- ;
    }
    void push( int a ) {
        arr[tam++] = a ;
    }
};

int N, R, Q ;
int N2, K=0 ;
int id2[limN], id3[limN] ;
int hom[limN], padre[limN] ;
bool usd[limN] ;
list<int> hijos[limN] ;
list <int> region[limR] ;
long long cache[limN2][limR] ;
int esp[limR], trans[limN2] ;
pila stck ;

void marca() {
    int W = 0, pos ;
    stck.push( 0 ) ;
    while( !stck.empty()  )  {
        pos = stck.top() ;
        if( usd[pos] ) {
            stck.pop() ;
            if( pos )
                id3[ padre[pos] ] = max( id3[ padre[pos] ],  id3[pos] ) ;
            continue ;
        }
        usd[pos] = 1 ;
        id2[pos] = W++ ;
        id3[pos] = id2[pos] ;
        region[ hom[pos] ].push_back( pos ) ;
        for( list<int>::iterator it=hijos[pos].begin(); it!=hijos[pos].end(); it++ )
            stck.push( *it ) ;
    }
}

long long query( int X, int Y ) {
    int res = 0LL ;
    list <int> :: iterator sup, inf ;
    int tmp ;
    sup = region[X].begin() ;
    inf = region[Y].begin() ;
    stck.tam = 0 ;

    while( sup != region[X].end()  ||  !stck.empty()  )  {
        if(  sup==region[X].end()  ||  ( !stck.empty() && stck.top()<id2[*sup] )    )  {
            tmp = stck.top() ;
            while( inf!=region[Y].end()  &&  id2[*inf]<=tmp  )  {
                res += stck.tam ;
                inf ++ ;
            }

            stck.pop() ;
        }
        else {
            tmp = id2[*sup] ;
            while( inf!=region[Y].end()  &&  id2[*inf]<=tmp  )  {
                res += stck.tam ;
                inf ++ ;
            }
            stck.push( id3[*sup] ) ;
            sup ++ ;
        }
    }

    return res ;
}


void granQuery( int X, int W ) {
    int res = 0LL ;
    list <int> :: iterator sup, inf[limR] ;
    int tmp ;
    sup = region[X].begin() ;
    for( int Y=0; Y<R; Y++ )
        inf[Y] = region[Y].begin() ;
    stck.tam = 0 ;

    while( sup != region[X].end()  ||  !stck.empty()  )  {
        if(  sup==region[X].end()  ||  ( !stck.empty() && stck.top()<id2[*sup] )    )  {
            tmp = stck.top() ;
            for( int Y=0; Y<R; Y++ ) {
                while( inf[Y]!=region[Y].end()  &&  id2[*inf[Y]]<=tmp  )  {
                    cache[W][Y] += stck.tam ;
                    inf[Y] ++ ;
                }
            }

            stck.pop() ;
        }
        else {
            tmp = id2[*sup] ;
            for( int Y=0; Y<R; Y++ ) {
                while( inf[Y]!=region[Y].end()  &&  id2[*inf[Y]]<=tmp  )  {
                    cache[W][Y] += stck.tam ;
                    inf[Y] ++ ;
                }
            }

            stck.push( id3[*sup] ) ;
            sup ++ ;
        }
    }

    return ;
}


int main() {
    scanf("%d%d%d", &N, &R, &Q ) ;
    scanf("%d", &hom[0] ) ;
    hom[0] -- ;
    padre[0] = -1 ;
    for( int i=1; i<N; i++ ) {
        scanf("%d%d", &padre[i], &hom[i] ) ;
        hom[i]--, padre[i] -- ;
        hijos[ padre[i] ].push_back(i) ;
    }

    marca() ;
    N2 = sqrt(N) ;
    for( int i=0; i<R; i++ )
        if( region[i].size()>=N2 )
            trans[ K++ ] = i ;

    for( int i=0; i<K; i++ ) {
        esp[ trans[i] ] = i+1 ;
        granQuery( trans[i], i ) ;
        /*for( int j=0; j<R; j++ ) {
            cache[i][j] = query(  trans[i],  j  ) ;
        }*/
    }

    for( int q=0; q<Q; q++ ) {
        int a, b ;
        long long c ;
        scanf("%d%d", &a, &b ) ;
        a--, b-- ;

        if( esp[a] ) {
            a = esp[a] -1 ;
            c = cache[a][b] ;
        }
        else {
            c = query( a, b ) ;
        }

        cout << c << endl ;
    }

    return 0 ;
}


