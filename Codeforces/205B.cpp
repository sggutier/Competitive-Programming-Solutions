#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int main() {
    int N ;
    long long arr[lim] ;
    long long res=0LL, maxN = 0LL, bon=0LL ;

    cin >> N ;
    for( int i=0; i<N; i++ ) {
        cin >> arr[i] ;
    }

    for( int i=0; i<N; i++ ) {
        arr[i] += bon ;
        if( arr[i]<maxN ) {
            res += maxN-arr[i] ;
            bon += maxN-arr[i] ;
        }
        else {
            maxN = max( maxN, arr[i] ) ;
        }
    }

    cout << res << endl ;

    return 0 ;
}

