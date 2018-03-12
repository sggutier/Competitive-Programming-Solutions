#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std ;

int main() {
	int N ;
	string tmp ;
	map <string,int> num ;
	int arr[3000] ;
	int res = 0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		cin >> tmp ;
		num[tmp] = i ;
	}
	for( int i=0; i<N; i++ ) {
		cin >> tmp ;
		arr[i] = num[tmp] ;
		for( int j=0; j<i; j++ ) 
			if( arr[j]<arr[i] )
				res ++ ;
	}
	
	printf("%d/%d\n", res, (N*(N-1))/2 ) ;
	
	return 0 ;
}
