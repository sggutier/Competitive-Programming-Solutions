#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100005 ;
#define parI pair< int,int >
#define parF pair< double, double >
#define p1 first
#define p2 second

struct nodo {
    int id, dpt ;
    nodo* ant ;
    nodo() {
	// ant = NULL ;
    }
    nodo( int _id ) {
	id = _id ;
	dpt = 0 ;
	ant = NULL ;
    }

    nodo* raiz() {
	if( ant==NULL )
	    return this ;
	return ant->raiz() ;
    }

    void une( nodo *B ) {
	nodo *A = raiz() ;
	B = B->raiz() ;
	if( A->dpt > B->dpt )
	    swap( A, B ) ;
	B -> ant = A ;
    }
};


int N, D ;
parF pts[lim] ;
pair< double, parI >  dsts[lim] ;
nodo *arr[lim] ;

void caso() ;


int main() {
    int T ;

    scanf("%d",&T ) ;
    for( int i=0; i<T; i++ ) {
	if( i )
	    printf("\n" ) ;
	caso() ;
    }
    
    return 0 ;
}

double calcDis( parF A, parF B ) {
    double x=A.p1 - B.p1, y=A.p2-B.p2 ;
    return sqrt( x*x + y*y ) ;
}

void caso() {
    double res = 1.0*0 ;
    int e = 1 ;
    D = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%lf%lf", &pts[i].p1, &pts[i].p2 ) ;
	arr[i] = new nodo(i) ;
    }

    D = 0 ;
    for( int i=0; i<N; i++ ) 
	for( int j=0; j<i; j++ ) 
	    dsts[D++] = make_pair( calcDis(pts[i],pts[j]), parI(i,j) ) ;

    sort( dsts, dsts+D ) ;
    
    for( int i=0; i<D and e<N;  i++ ) {
	int a = dsts[i].p2.p1, b = dsts[i].p2.p2 ;
	if( arr[a]->raiz() == arr[b]->raiz()  )
	    continue ;
	
	e ++ ;
	res += dsts[i].p1 ;
	arr[a] -> une( arr[b] ) ;
    }

    for( int i=0; i<N; i++ )
	delete arr[i] ;

    printf("%.2lf\n", res ) ;
}
