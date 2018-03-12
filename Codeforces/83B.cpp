#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std ;
#define par pair<long long,int>
#define f first
#define s second
#define lim 100005

int main() {
	int N ;
	long long K ;
	long long sum = 0LL ;
	par arr[lim] ;
	int i, j, w ;
	par res[lim] ;
	
	cin >> N >> K ;
	for( i=0; i<N; i++ ) {
		cin >> arr[i].f ;
		arr[i].s = i ;
		sum += arr[i].f ;
	}
	
	if( K>sum ) {
		cout << -1 << endl ;
		return 0 ;
	}
	
	sort ( arr, arr+N ) ;
	sum = 0LL ;
	for( i=0; i<N; i++ ) {
		if( arr[i].f <=sum ) 
			continue ;
		arr[i].f -= sum ;
		w = (N-i) ;
		if( K<arr[i].f*w )  {
			arr[i].f += sum ;
			/*cout << K << endl ;
			for( j=i; j<N; j++ ) {
				cout << arr[j].f-sum << " " ;
			}
			cout << endl ;
			for( j=i; j<N; j++ ) {
				cout << arr[j].s << " " ;
			}
			cout << endl ;*/
			for( j=i; j<N; j++ ) {
				arr[j].f -= sum ;
				arr[j].f -= K/w ;
			}
			K %= w ;
			break ;
		}
		else {
			K -= arr[i].f*w ;
			arr[i].f += sum ;
		}
		sum = arr[i].f ;
	}
	
	/*for( j=i; j<N; j++ ) {
		cout << arr[j].f << " " ;
	}
	cout << endl ;
	for( j=i; j<N; j++ ) {
		cout << arr[j].s << " " ;
	}
	cout << endl ;*/
	
	w = 0 ;
	for( ; i<N; i++ ) {
		res[w++] = par(  arr[i].s, arr[i].f )  ;
	}
	sort( res, res+w ) ;
	for( i=0; i<K; i++ ) {
		res[i].s -- ;
	}
	for( ; i<w; i++ ) {
		if( res[i].s ) 
			cout << res[i].f+1	 << " " ;
	}
	for( i=0; i<K; i++ ) {
		if( res[i].s )
			cout << res[i].f+1	 << " " ;
	}
	printf("\n" ) ;
	
	return 0 ;
}
