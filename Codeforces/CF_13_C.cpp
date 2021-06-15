#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 5003

int N ;
long long arr[lim] ;

long long dif( long long w ) {
	long long ant ;
	ant = arr[0]-w ;
	for( int j=1; j<N; j++ ) {
		if( arr[j]<ant )
			w += ant-arr[j] ;
		else
			ant = arr[j] ;
	}
	return w ;
}

int main() {
	long long ini=0LL, fin=(1LL<<60), piv ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) 
		cin >> arr[i] ;
		
	while( ini<fin ) {
		piv = (ini+fin)/2LL ;
		if( dif(piv)<=dif(piv+1) )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	
	cout << dif(ini) << endl ;
	
	return 0 ;
}
