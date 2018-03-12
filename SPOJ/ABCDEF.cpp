#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <map>
using namespace std ;
const int limN = 100 ;
const int limW = limN*limN*limN ;

int nA=0, nB=0 ;
int A[limW], B[limW] ;

int main() {
	int N ;
	int arr[limN] ;
	long long res = 0LL ;
	map <int,int> :: iterator X, Y ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			for( int k=0; k<N; k++ ) {
				int x= arr[i]*arr[j]+arr[k], y=arr[i]*(arr[j]+arr[k]) ;
				A[nA++] = x ;
				if( arr[i]==0 )
					continue ;
				B[nB++] = y ;
			}
		}
	}

	sort( A, A+nA ) ;
	sort( B, B+nB ) ;

	for( int i=0, j=0; i<nA && j<nB; ) {
		while( j<nB && B[j]<A[i] ) {
			j++ ;
		}
		if( j>=nB || A[i]<B[j] ) {
			i ++ ;
			continue ;
		}
		long long X=0LL, Y=0LL ;
		do { 
			X ++ ;
			i ++ ;
		}while( i<nA && A[i]==A[i-1] ) ;
		
		do {	
			Y ++ ;
			j ++ ;
		}while( j<nB && B[j]==B[j-1] ) ;
		res += X*Y ;
	}

	cout << res << endl ;

	return 0 ;
}
