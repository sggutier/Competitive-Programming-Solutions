#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
const int lim = 20 ;
const int limB = (1<<lim) ;
const int inf = 2000000001 ;

struct rng {
	int ini, fin, val ;
	rng() {
	}
	rng( int x, int y, int z ) {
		ini = x ;
		fin = y ;
		val = z ;
	}
};

bool operator<( rng A, rng B ) {
	if( A.val!=B.val ) {
		return A.val < B.val ;
	}
	if( A.ini != B.ini )
		return A.ini < B.ini ;
	return A.fin < B.fin ;
}

bool funca( rng A, rng B ) {
	if( A.ini != B.ini )
		return A.ini<B.ini ;
	if( B.fin != B.fin )
		return A.fin<B.fin ;
	return A.val<B.val ;
}

int N, W=0 ;
int A[lim], B[lim] ;
int X=0 ;
rng comb[limB] ;
priority_queue <par> Q ;
set <int> numUsd ;

int main() {
	int K = 0 ;
	int res = (1<<30), resA, resB ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &A[i] ) ;
	}
	for( int i=0; i<N; i++ ) {
		scanf("%d", &B[i] ) ;
		W += B[i] ;
	}

	for( int b=(1<<N)-1; b>=0; b-- ) {
		int sumA=0, sumB=0, sumA2=0, tmp=0 ;
		for( int i=0; i<N; i++ ) {
			if( (1<<i) & b ) {
				if( A[i] ) {
					sumA ++ ;
					sumA2 += A[i] ;
				} 
				else {
					tmp = 1 ;
					break ;
				}
			}
			else {
				sumB += B[i] ;
			}
		}

		if( sumA==0 || tmp==1 ) 
			continue ;

		if( sumB==W )
			sumB = inf ;
		sumB ++ ;

		numUsd.insert( sumA ) ;
		numUsd.insert( sumA2 ) ;
		comb[X++] = rng( sumA, sumA2, sumB ) ;
	}
	sort( comb, comb+X, funca ) ;

	for( set<int>::iterator it=numUsd.begin(); it!=numUsd.end(); it++ ) {
		int act = *it ;
		while( K<X && comb[K].ini<=act )  {
			Q.push(  par(comb[K].val,comb[K].fin)  ) ;
			K ++ ;
		}
		while( !Q.empty() && Q.top().s<act ) 
			Q.pop() ;
		if( Q.empty() )
			continue ;
		int dos=Q.top().f ;

		if( dos==inf )
			continue ;

		if( act+dos<res ) {
			res = act+dos ;
			resA = act ;
			resB = dos ;
		}
		else if( act+dos==res && act>resA ) {
			resA = act ;
			resB = dos ;
		}
	}

	printf("%d %d\n", resA, resB ) ;

	return 0 ;
}


