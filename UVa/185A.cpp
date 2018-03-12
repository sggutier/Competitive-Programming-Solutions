#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define mod 1000000007LL

long long pot( long long N ) {
    if( N==0 )
        return 1LL ;
    long long tmp = pot(N/2) ;
    if( N%2LL )
        return (tmp*tmp*2LL)%mod ;
    else
        return (tmp*tmp)%mod ;
}

int main() {
    long long N ;
    long long res ;

    cin >> N ;
    res = pot(N) ;

    cout <<  ( (res*(res+1LL))/2LL  )%mod << endl ;

    return 0 ;
}


