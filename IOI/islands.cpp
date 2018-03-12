#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <utility>
#include <queue>
#include <stack>
using namespace std ;
/* Macros */
#define lim 1000006
#define par pair< int , int >
#define f first
#define s second


struct cola {
    int tam ;
    int arr[lim] ;
    cola() {
        tam = 0 ;
    }
    void pop() {
        tam -- ;
    }
    void push( int A ) {
        arr[tam++] = A ;
    }
    int top() {
        return arr[tam-1] ;
    }
    bool empty() {
        return tam==0 ;
    }
};


int N, W ;
int padre[lim] ;
int dis[lim] ;
list< int > adj[lim] ;
bool usd[lim] ;
int ciclo[2*lim] ;
long long maxProf[lim], maxProf2[lim] ;
cola Q ;
//stack <int> Q ;
int moo = 0 ;



void barre( long long &resT ) {
    if( W==1 ) {
        return ;
    }

    long long sumD = 0LL, sumI=0LL, rev=0LL ;
    long long sumD2 = 0LL, sumI2=0LL ;
    int ini=ciclo[0], fin=ini ;

    for( int i=0; i<W; i++ )
        rev += dis[ ciclo[i] ] ;

    ini = ciclo[0] ;
    fin = padre[ini] ;
    sumI = maxProf[ini] ;
    sumI2 = sumI ;
    sumD = dis[ini] ;
    sumD2 = sumD ;
    while( ini!=fin ) {

        resT = max( resT, sumD + sumI + maxProf[ fin ] ) ;
        if( maxProf[ fin ] >= sumD + sumI ) {
            sumI = maxProf[ fin ] ;
            sumD = 0LL ;
        }
        resT = max( resT, rev -sumD2 + sumI2 + maxProf[ fin ] ) ;
        if( maxProf[ fin ] >= -sumD2 + sumI2 ) {
            sumI2 = maxProf[ fin ] ;
            sumD2 = 0LL ;
        }

        sumD += dis[fin] ;
        sumD2 += dis[fin] ;
        fin = padre[fin] ;
    }
}

void diamArb( int ini, long long &resT ) {
    usd[ini] = 0 ;
    Q.push(ini) ;
    while( !Q.empty() ) {
        int pos = Q.top() ;

        if( usd[pos] ) {
            moo ++ ;
            Q.pop() ;
            resT = max( resT, maxProf[pos] + maxProf2[pos] ) ;
            if( pos==ini )
                continue ;
            if( maxProf2[ padre[pos] ] < maxProf[pos] + dis[pos]  )  {
                maxProf2[ padre[pos] ] = maxProf[pos] + dis[pos] ;
                if( maxProf[ padre[pos] ] < maxProf2[ padre[pos] ] )
                    swap( maxProf[ padre[pos] ] , maxProf2[ padre[pos] ] ) ;
            }
        }
        else {
            usd[pos] = 1 ;
            for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
                if( !usd[*it] )
                    Q.push(*it) ;
            }
        }
    }
}

void buscaCiclo( int pos ) {
    int k ;
    W = 0 ;

    while( !usd[pos] ) {
        usd[pos] = 1 ;
        ciclo[ W++ ] = pos ;
        pos = padre[pos] ;
    }

    for( k=0; ciclo[k]!=pos; k++ )
        usd[ ciclo[k] ] = 0 ;

    W -= k ;
    for( int i=0; i<W; i++ )
        ciclo[i] = ciclo[i+k] ;
}
//////////////////////////////////////////////////

int main() {
    //long long res = 0LL, resT ;

    //scanf("%d", &N ) ;
    //for( int i=0; i<N; i++ ) {
        //int a, b, c ;
        //a = i ;
	//scanf("%d%d", &a, &b ) ;
        //b -- ;
        //adj[b].push_back( a ) ;
        //padre[i] = b ;
        //dis[i] = c ;
    //}
//
    //for( int i=0; i<N; i++ ) {
        //if( usd[i] )
            //continue ;
        //resT = 0LL ;
        //buscaCiclo( i ) ;
        //for( int j=0; j<W; j++ )
            //diamArb( ciclo[j], resT ) ;
        //barre( resT ) ;
//
        //res += resT ;
    //}

    //cout << (res+1)/2 << endl ;

    while( 1 ) {
	    int DP[100][100] ;

	    cin >> N ;
	    for( int i=0; i<N; i++ ) {
		    DP[i][i] = 1 ;
		    DP[i][0] = 1 ;
		    for( int j=1; j<i; j++ ) 
			    DP[i][j] = DP[i-1][j] + DP[i-1][j-1] ;
		    for( int j=0; j<=i; j++ )
			    cout << DP[i][j] << " " ;
		    cout << endl ;
	    }

    }

    return 0 ;
}
