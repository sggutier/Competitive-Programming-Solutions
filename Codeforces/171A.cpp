#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    long long A, B ;
    long long C=0LL ;

    cin >> A >> B ;
    while( B ) {
        C *= 10 ;
        C += (B%10) ;
        B /= 10 ;
    }

    cout << A+C << endl ;

    return 0 ;
}
