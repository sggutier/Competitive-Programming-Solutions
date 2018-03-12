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
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

struct nodo {
    int val ;
    nodo *L, *R ;
    nodo() {
    }
    nodo(int x) {
	val = x ;
	L = NULL ;
	R = NULL ;
    }
    bool sumaN( int X ) {
	// cout << X << " " << val << endl ;
	if( L==NULL and R==NULL )
	    return val == X ;
	return ( L==NULL? false : L -> sumaN(X-val) )
	    or ( R==NULL? false : R -> sumaN(X-val) ) ;
    }
    ~nodo() {
	if( L!=NULL )
	    delete L ;
	if( R!=NULL )
	    delete R ;
    }
};


void lee( nodo** act ) {
    char c ;
    while( scanf("%c",&c)!=EOF and c!=')' and !isdigit(c) and c!='-' ) ;
    if( c==')' )
	return ;

    int crg = 0 ;

    if( c=='-' ) {
	// cout << "wtf mang" << endl ;
	while( scanf("%c",&c)!=EOF and c!=')' and !isdigit(c) ) ;
	crg = -(c-'0') ;
	while( scanf("%c",&c)!=EOF and isdigit(c) )
	    crg = crg*10 - (c-'0') ;
    }
    else {
	crg = c-'0' ;
	while( scanf("%c",&c)!=EOF and isdigit(c) )
	    crg = crg*10 + c-'0' ;
    }

    (*act) = new nodo(crg) ;
    // lee( (*act).L ) ;
    lee( &( (*act) -> L) ) ;
    lee( &( (*act) -> R) ) ;
    while( scanf("%c",&c)!=EOF and c!=')' ) ;
}

void caso( int K ) {
    nodo** nov ;
    //nodo* tmp ;

    nov = new nodo* ;
    // tmp = *nov ;

    // cout << K << endl ;

    lee( nov ) ;

    if( (*nov)!=NULL and (*nov)->sumaN(K) )
	printf("yes\n" ) ;
    else
	printf("no\n" ) ;

    //if( tmp!=NULL )
    //delete tmp ;

    //return ;
    //if( nov!=NULL )
    delete nov ;
}

int main() {
    int K ;
    
    while( scanf("%d",&K)!=EOF )
    	caso(K) ;
    
    return 0 ;
}
