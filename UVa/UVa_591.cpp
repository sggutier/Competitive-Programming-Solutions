#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int N ;
int arr[500] ;

int main() {
    int t = 1 ;
    while( scanf("%d", &N) && N ) {
	int tot = 0, res = 0 ;
	for( int i=0; i<N; i++ ) {
	    scanf("%d", &arr[i] ) ;
	    tot += arr[i] ;
	}
	tot /= N ;
	for( int i=0; i<N; i++ ) {
	    res += abs(arr[i]-tot) ;
	}
	printf("Set #%d\nThe minimum number of moves is %d.\n", t++, res/2 ) ;
	printf("\n" ) ;
    }
    
    return 0 ;
}
