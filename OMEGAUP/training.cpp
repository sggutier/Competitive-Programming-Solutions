#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <list>
using namespace std ;
#define limN 1005
#define limM 5005
#define limB 1024
#define f first
#define s second
typedef pair<int,int> par ;


int N, E ;
int edg[limM][3] ;
list <int> adj[limN] ;
list <int> cicl[limN][limB] ;
char matAdj[limN][limN] ;
int padre[limN], prof[limN], numHijos[limN] ;
int dp[limN][limB] ;
char usd[limN][limB] ;
int rSum = 0 ;

void arbol( int pos, int ant, int p ) ;
void lca( int A, int B, int id ) ;
int memo( int raiz, int masc ) ;
int quita( int masc, int id ) ;


int main() {

    scanf("%d%d", &N, &E ) ;
    for( int i=0; i<E; i++ ) {
        for( int j=0; j<3; j++ )
            scanf("%d", &edg[i][j] ) ;
        edg[i][0]--, edg[i][1]-- ;
        rSum += edg[i][2] ;
        if( edg[i][2]==0 ) {
            adj[ edg[i][0] ].push_back( edg[i][1] ) ;
            adj[ edg[i][1] ].push_back( edg[i][0] ) ;
        }
    }

    arbol( 0, -1, 1 ) ;
    for( int i=0; i<E; i++ ) {
        if( edg[i][2]==0 )
            continue ;
        lca( edg[i][0], edg[i][1], i ) ;
    }

    /*for( int i=0; i<N; i++ ) {
        printf("%d: -> %d -> %d %d\n", i+1, numHijos[i], padre[i]+1, prof[i] ) ;
        for( int b=0; b<=(1<<numHijos[i])-1; b++ ) {
            for( list<int>::iterator it=cicl[i][b].begin(); it!=cicl[i][b].end(); it++ ) {
                printf("     %d -> %d %d %d\n", b, edg[*it][0]+1, edg[*it][1]+1, edg[*it][2] ) ;
            }
        }
    }*/

    cout << rSum - memo( 0, (1<<numHijos[0])-1 )  << endl ;
    //cout << rSum << endl ;

    return 0 ;
}

int quita( int masc, int id ) {
    int A, B ;
    int le=0, ro=0 ;
    int res = edg[id][2] ;

    A = edg[id][0] ;
    B = edg[id][1] ;
    if( prof[A]>prof[B] )
        swap( A, B ) ;

    while( prof[B]>prof[A] ) {
        res += memo( B, (1<<numHijos[B])-1-ro ) ;
        ro = 1<<matAdj[ padre[B] ][B] ;
        B = padre[B] ;
    }
    while( A!=B ) {
        res += memo( A, (1<<numHijos[A])-1-le ) ;
        res += memo( B, (1<<numHijos[B])-1-ro ) ;
        le = 1<<matAdj[ padre[A] ][A] ;
        A = padre[A] ;
        ro = 1<<matAdj[ padre[B] ][B] ;
        B = padre[B] ;

    }

    le |= ro ;
    res += memo( A, masc-le ) ;

    /*cout << A+1 << " " << masc-le << " " ;
    A = edg[id][0] ;
    B = edg[id][1] ;
    cout << A+1 << " " << B+1 << " " << res << endl ;*/

    return res ;
}

int memo( int raiz, int masc ) {
    if( usd[raiz][masc] )
        return dp[raiz][masc] ;
    usd[raiz][masc] = 1 ;

    int tmp=0 ;
    for( list<int>::iterator it=adj[raiz].begin(); it!=adj[raiz].end(); it++ ) {
        if( *it!=padre[raiz] ) {
            if( (1<<tmp) & masc  )
                dp[raiz][masc] += memo( *it, (1<<numHijos[*it])-1 ) ;
            tmp ++ ;
        }
    }

    for( list<int>::iterator it=cicl[raiz][masc].begin(); it!=cicl[raiz][masc].end(); it++ )
        dp[raiz][masc] = max( dp[raiz][masc], quita(masc,*it)  ) ;

    return dp[raiz][masc] ;
}

void lca( int A, int B, int id ) {
    int x=A, y=B ;

    int res = 0 ;
    int le=0, ro=0 ;
    int dis = 0 ;
    if( prof[A]>prof[B] )
        swap( A, B ) ;

    while( prof[B]>prof[A] ) {
        ro = 1<<matAdj[ padre[B] ][B] ;
        B = padre[B] ;
        dis ++ ;
    }
    while( A!=B ) {
        le = 1<<matAdj[ padre[A] ][A] ;
        A = padre[A] ;
        ro = 1<<matAdj[ padre[B] ][B] ;
        B = padre[B] ;
        dis += 2 ;
    }

    if( dis%2 ) {
        return ;
    }

    le |= ro ;
    //cout << " -- " << x+1 << " " << y+1 << " " << A+1  << " " << edg[id][2] << endl ;
    for( int b=(1<<numHijos[A])-1; b>=0; b-- )
        if(  (b&le)==le  )
            cicl[A][b].push_back( id ) ;
}

void arbol( int pos, int ant, int p ) {
    padre[pos] = ant ;
    prof[pos] = p ;
    int w = 0 ;
    for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
        if( *it==ant )
            continue ;
        matAdj[pos][*it] = w++ ;
        arbol( *it, pos, p+1 ) ;
    }
    numHijos[pos] = w ;
}
