#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100005 ;

int revo( int N ) {
    int res = 0 ;
    while( N>0 and N%10==0 )
	N /= 10 ;
    while( N>0 ) {
	res *= 10 ;
	res += N%10 ;
	N /= 10 ;
    }
    return res ;
}

void caso() {
    int A, B ;

    scanf("%d%d", &A, &B ) ;
    A = revo(A) ;
    B = revo(B) ;
    printf("%d\n", revo(A+B) ) ;
    //cout << A << " " << B << endl ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
