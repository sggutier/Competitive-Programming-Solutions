#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int main() {
	string A, B ;
	int N ;
	int x=0, y=0 ;
	
	cin >> A >> B ;
	
	N = A.size() ;
	
	for( int i=0; i<N; i++ ) {
		if( A[i]==B[i] ) 
			continue ;
		if( A[i]=='4' )
			x ++ ;
		else
			y ++ ;
	}
	
	printf("%d\n", max( x, y )  ) ;
	
	return 0 ;
}
