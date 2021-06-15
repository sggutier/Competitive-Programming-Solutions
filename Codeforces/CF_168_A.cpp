#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int a, b, c ;
    int res = 0 ;

    cin >> b >> a >> c ;
    while( a*100 < b*c ) {
        a ++ ;
        res ++ ;
    }

    cout << res << endl ;

    return 0 ;
}
