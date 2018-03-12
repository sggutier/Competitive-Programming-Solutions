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
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

void caso( int N ) {
    if( N<=1 ) {
        printf("1\n" ) ;
        return ;
    }

    int pt=1, res=0 ;

    for( int i=1; i<=N; i++ )  {
        pt = (pt*i)%9 ;
        res = (res+pt)%9 ;
    }

    printf("%d\n", pt ) ;
}

int main() {
    int N ;

    while( scanf("%d", &N ) != EOF )
        caso( N ) ;
    return 0 ;
}
