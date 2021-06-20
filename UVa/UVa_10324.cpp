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
const int lim = 1000005 ;

char arr[lim] ;
int sum[lim] ;

int main() {
    int T = 0 ;
    
    while( scanf("%s",arr)!=EOF  ) {
	int N = strlen(arr), Q ;

	printf("Case %d:\n", ++T ) ;
	
	sum[0] = 0 ;
	for( int i=0; i<N; i++ )
	    sum[i+1] = sum[i] + (arr[i]=='1') ;

	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
	    int a, b ;
	    scanf("%d%d", &a, &b ) ;
	    if( a>b )
		swap( a, b ) ;
	    b ++ ;
	    printf("%s\n", ( (sum[b] - sum[a])%(b-a)==0 )? "Yes" : "No" ) ;
	}
    }
    
    return 0 ;
}
