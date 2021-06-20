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

int GCD( int a, int b ) {
    int c ;
    while( b ) {
	c = b ;
	b = a%b ;
	a = c ;
    }
    return a ;
}

int main() {
    int N ;
    long long G ;
    int i, j ;

    while( scanf("%d",&N)!=EOF and N!=0 ) {
	G=0LL;
	for(i=1;i<N;i++)
	    for(j=i+1;j<=N;j++)
		{
		    G+=GCD(i,j);
		}
	printf("%lld\n", G ) ;
    }
    
    return 0 ;
}
