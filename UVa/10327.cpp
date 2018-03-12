#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso( int N ) {
    int arr[1005], res =  0 ;

    for( int i=0; i<N; i++ ) {
	scanf("%d", &arr[i] ) ;
	for( int j=i-1; j>=0 && arr[j]>arr[j+1]; swap(arr[j+1],arr[j]), j--, res++ ) ;
    }
    printf("Minimum exchange operations : %d\n", res ) ;
}

int main() {
    int N ;

    while( scanf("%d",&N) != EOF ) {
	caso(N) ;
    }
    
    return 0 ;
}
