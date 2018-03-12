#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = (1<<30) ;
const int lim = 1e6 + 5 ;
const double eps = 1e-9 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;
const int limB = 26 ;

struct node {
    int nSons ;
    node *sons[limB] ;
    node() {
	nSons = 0 ;
	for( int i=0; i<limB; i++ )
	    sons[i] = NULL ;
    }
    ~node() {
	for( int i=0; i<limB; i++ )
	    if( sons[i]!=NULL )
		delete sons[i] ;
    }

    int insert( int N, int pos, char *S ) {
	if( pos==N ) {
	    return 0 ;
	}
	int res = 0 ;
	if( sons[ S[pos]-'a' ]==NULL ) {
	    sons[ S[pos]-'a' ] = new node() ;
	    nSons ++ ;
	    res = 1 ;
	    sons[ S[pos]-'a' ] -> insert( N, pos+1, S ) ;
	}
	else 
	    res = sons[ S[pos]-'a' ] -> insert( N, pos+1, S ) + 1 ;
	
	return res ;
    }
};

char *arr ;

int tCase() {
    long long res = 0LL ;
    node *trie = new node() ;
    int N ;

    scanf( "%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%s", arr ) ;
	int a = strlen(arr) ;
	int tmp = trie -> insert( a, 0, arr ) ;
	res += tmp ;
    }
    
    delete trie ;

    return res ;
}

int main() {
    int T ;

    arr = new char[lim] ;

    scanf( "%d", &T ) ;
    for( int i=1; i<=T; i++ ) {
	printf("Case #%d: %d\n", i, tCase() ) ;
    }

    delete[] arr; 
    
    return 0 ;
}
