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

int apr[lim] ;

void caso(int Z, int I, int M, int L) {
    int act = 1 ;
    memset( apr, 0, sizeof(apr)  ) ;
    while( !apr[L] ) {
	apr[L] = act++ ;
	L = ( Z*L + I ) % M ;
    }
    printf("%d\n", act-apr[L] ) ;
}

int main() {
    int Z, I, M, L ;
    int t = 0 ;

    while( scanf("%d%d%d%d", &Z, &I, &M, &L ) !=EOF
	   and ( Z or I or M or L ) ) {
	printf("Case %d: ", ++t ) ;
	caso( Z, I, M, L ) ;
    }
    
    return 0 ;
}
