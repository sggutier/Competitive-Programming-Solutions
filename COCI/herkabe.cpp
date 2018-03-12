#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std ;
const long long mod = 1000000007LL ;
const int lim = 30005 ;

int N ;
string arr[lim] ;
long long fact[30] ;

long long calc( int ini, int fin, int pos ) {
	if( ini==fin ) {
		return 1LL ;
	}
	if( pos+1==arr[ini].size() ) {
		long long K = (calc(ini+1,fin,pos)*2LL)%mod ;
		return K ;
	}
	int a=ini, b=a+1, w=0 ;
	long long res = 1LL ;
	
	pos ++ ;
	
	while( a<=fin ) {
		while( b<=fin && arr[b][pos]==arr[a][pos] ) 
			b ++ ;
		res = (res*calc( a, b-1, pos ))%mod ;
		a = b ;
		b = a+1 ;
		w ++ ;
	}

	return (res*fact[w])%mod ;
}

int main() {
	char tmp[lim] ;
	
	fact[0] = 1LL ;
	for( int i=1; i<30; i++ )
		fact[i] = (fact[i-1]*i)%mod ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", tmp ) ;
		arr[i] = tmp ;
		arr[i] = "W" + arr[i] + "4" ;
	}
	sort( arr, arr+N ) ;

	cout << calc(0,N-1,0) << endl ;
	
	return 0 ;
}
