#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso( int N ) {
    int arr[1005], tot=0, w=0 ;
    int res = 0 ;
    for( int i=0; i<N; i++ ) {
	int a, b ;
	scanf("%d.%d", &a, &b ) ;
	arr[i] = a*100 + b ;
	tot += arr[i] ;
    }
    w = N - tot%N ;
    tot /= N ;
    for( int i=0; i<N && w; i++ ) {
	if( arr[i]==tot ) {
	    arr[i] = -1 ;
	    w -- ;
	}
    }
    for( int i=0; i<N && w; i++ ) {
	if( arr[i]!=-1 && arr[i]<tot ) {
	    res += tot-arr[i] ;
	    arr[i] =  -1 ;
	    w -- ;
	}
    }
    for( int i=0; i<N && w; i++ ) {
	if( arr[i]!=-1  ) {
	    res += abs(-tot+arr[i]) ;
	    arr[i] = -1 ;
	    w -- ;
	}
    }
    for( int i=0; i<N; i++ ) {
	if( arr[i]!=-1 ) {
	    res += abs(1+tot-arr[i]) ;
	}
    }

    res /= 2 ;
    
    printf("$%d.%02d\n", res/100, res%100 ) ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF && N )
	caso(N ) ;

    return 0 ;
}
 
