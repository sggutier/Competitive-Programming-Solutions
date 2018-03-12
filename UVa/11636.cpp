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

void caso( int N ) {
    int res = 0, tmp=1 ;
    while( tmp<N ) {
	res ++ ;
	tmp *= 2 ;
    }
    //return res ;
    printf("%d\n", res ) ;
}

int main() {
    int N ;
    int t = 1 ;

    while( scanf("%d",&N)!=EOF  and  N>=0 ) {
	printf("Case %d: ", t++ ) ;
	caso(N) ;
    }
    
    return 0 ;
}
