#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N ;
    int arr[3] ;

    scanf("%d", &N ) ;
    for( int i=1; i<=N; i++ ) {
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2] );
	sort( arr, arr+3 ) ;
	printf("Case %d: %d\n", i, arr[1] ) ;
    }
    
    return 0 ;
}
