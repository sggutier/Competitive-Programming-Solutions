#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
    int N ;
    long long arr[1000] ;
    long long res = 0LL ;
	
    cin >> N ;
    for( int i=0; i<N; i++ ) 
	cin >> arr[i] ;
	
    for( int i=0; i<N; i++  ) {
	res += arr[i]*(i+1LL) ;
	res -= i ;
    }
	
    cout << res << endl ;
	
    return 0 ;
}
