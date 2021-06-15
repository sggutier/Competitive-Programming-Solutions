#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;

int main() {
    int a, b, c ;

    cin >> a >> b >> c ;

    cout <<  ceil( (c*(a-b))/(b*1.0) )  << endl ;

    return 0 ;
}
