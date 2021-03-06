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
const int lim = 100005 ;
const int nInf = -(1<<30) ;
#define par pair<int,int>
#define f first
#define s second

vector <par> arr[6] ;

int cala( int W ) {
	int res = 0 ;
	for( int K=0; K<6; K++ ) {
		int ini=0, fin=arr[K].size()-1 ;
		while( ini<fin ) {
			int piv = (ini+fin)/2 ;
			if( arr[K][piv].f < W )
				ini = piv+1 ;
			else
				fin = piv ;
		}
		if( arr[K][ini].f < W )
			return -nInf ;
		res += arr[K][ini].s ;
	}
	return res ;
}

int main() {
	int N, T ;
	int ini=0, fin=-nInf ;

	scanf("%d%d", &N, &T ) ;
	for( int i=0; i<N; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		arr[a-1].push_back( par(c,b) ) ;
	}

	for( int i=0; i<6; i++ ) {
		if( arr[i].size()==0 ) {
			printf("0\n" ) ;
			return 0 ;
		}
		sort( arr[i].begin(), arr[i].end() ) ;
		for( int j=arr[i].size()-2; j>=0; j-- ) 
			arr[i][j].s = min( arr[i][j].s, arr[i][j+1].s ) ;
	}

	while( ini<fin ) {
		int piv = (ini+fin)/2+1 ;
		if( cala(piv)<=T )
			ini = piv ;
		else
			fin = piv-1 ;
	}

	printf("%d\n", ini ) ;

	return 0 ;
}


