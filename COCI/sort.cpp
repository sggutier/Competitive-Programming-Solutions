#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int N ;
int arr[lim], rep[lim] ;

void mete( int pos ) {
	for( ; pos<lim; pos+=(pos & -pos)  )  {
		rep[pos] ++ ;
	}
}

int saca( int pos ) {
	int res = 0 ;
	for( ; pos>0; pos -= (pos & -pos)  )  {
		res += rep[pos] ;
	}
	return res ;
}

int main() {
	long long res = 0LL ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
	
	for( int i=0; i<N; i++ ) {
		int j ;
		for( j=i+1; j<N && arr[j]<arr[j-1]; j++ ) ;
		reverse( arr+i, arr+j ) ;
		if( j>i+1 )
			res ++ ;
		i = j-1 ;
	}
	
	for( int i=N-1; i>=0; i-- ) {
		res += saca( arr[i] ) ;
		mete( arr[i] ) ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}


