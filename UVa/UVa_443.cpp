#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const long long inf = 2e9 + 1LL ;
const int lim = 1e5 + 5 ;

int R = 0 ;
int arr[lim] ;

int main() {
    for( long long a=1LL; a<inf; a*=2 )
	for( long long b=1LL; a*b<inf; b*=3 )
	    for( long long c=1LL; a*b*c<inf; c*=5 )
		for( long long d=1LL; a*b*c*d<inf; d*=7 )
		    arr[R++] = a*b*c*d ;

    sort( arr, arr+R ) ;
    int N ;
    char res[][5] = { "th", "st", "nd", "rd" } ;

    while( scanf("%d",&N)!=EOF and N!=0 ) {
	int k = 0;
	if( (N/10)%10!=1 and (N-1)%10 <= 2 )
	    k = N%10 ;
	printf("The %d%s humble number is %d.\n", N, res[k], arr[N-1] ) ;
    }
    
    return 0 ;
}
