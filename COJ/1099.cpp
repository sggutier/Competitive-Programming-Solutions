#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int arr[3] ;

    scanf("%d", &arr[0] ) ;
    while( arr[0] ) {
        scanf("%d%d", &arr[1], &arr[2] ) ;
        sort( arr, arr+3 ) ;
        if( arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]  )
            printf("right\n" ) ;
        else
            printf("wrong\n" ) ;
        scanf("%d", &arr[0] ) ;
    }

    return 0 ;
}
