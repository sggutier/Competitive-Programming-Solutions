#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std ;
#define lim 3005
typedef pair<int,int> par ;
typedef long long ll ;
#define f first
#define s second

int main() {
	int N ;
	par arr[lim] ;
	ll res[lim] ;
	int i, j ;
	ll tmp ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) 
		scanf("%d%d", &arr[i].f, &arr[i].s ) ;
		
	sort( arr, arr+N ) ;
	res[0] = 0LL + arr[0].s ;
	for( i=1; i<N; i++ ) {
		tmp = 1LL<<60 ;
		for( j=0; j<i; j++ ) {
			tmp = min( tmp, res[j] ) ;
			res[j] += arr[i].f - arr[j].f ;
		}
		res[i] = tmp + arr[i].s ;
	}
	
	tmp = 1LL<<60 ;
	for( i=0; i<N; i++ )
		tmp = min( tmp, res[i] ) ;
	cout << tmp << endl ;
	
	return 0 ;
}
