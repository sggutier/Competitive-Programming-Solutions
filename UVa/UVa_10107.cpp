#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std ;

long long med( int N, long long *arr ) {
    if( N%2 )
	return arr[N/2] ;
    else
	return (arr[N/2]+arr[N/2-1])/2 ;
}

int main() {
    int N=0 ;
    long long arr[100005] ;

    while( scanf("%lld", &arr[N]) != EOF ) {
	N ++ ;
	for( int i=N-1; i>0 &&  arr[i]<arr[i-1]; i-- )
	    swap( arr[i], arr[i-1] ) ;
	printf("%lld\n", med( N, arr ) ) ;
    }
    
    return 0 ;
}
