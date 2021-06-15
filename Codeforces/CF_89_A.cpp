#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	//aoeueueou
	int n;
	long long res = 0LL ;
	long long m, k, w  ;
	int arr[10000] ;
	int i ;
	
	cin >> n >> m >> k ;
	for( i=0; i<n; i++ )
		scanf("%d", &arr[i] ) ;
	
	if( n%2==0 ) {
		printf("0\n" ) ;
		return 0 ;
	}
	
	w = n/2 + 1LL ;
	w = (m/w) ;
	res = w*k ;
	for( i=0; i<n; i+=2 )
		res = min( res, 0LL + arr[i] ) ;
		
	cout << res << endl ;
	
	return 0 ;
}
