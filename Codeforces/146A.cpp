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
	int N ;
	string S ;
	int sum = 0 ;
	
	cin >> N ;
	cin >> S ;
	
	for( int i=0; i<N; i++ ) {
		if( S[i] != '4' && S[i] != '7' ) {
			printf("NO\n" ) ;
			return 0 ;
		}
	}
	
	for( int i=0; i*2<N; i++ ) {
		sum += S[i] ;
	}
	for( int i=N/2; i<N; i++ ) {
		sum -= S[i] ;
	}
	
	if( sum==0 )
		cout << "YES" << endl ;
	else 
		cout << "NO" << endl ;
	
	return 0 ;
}
