#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std ;
const int lim = 100005 ;
#define f first
#define s second
typedef long long ll ;
typedef pair<int, int> par;

int N ;
string nms[lim][2] ;
int finA[lim] ;
char tmp[70] ;

int main() {
    string act = "" ;
    
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	for( int j=0; j<2; j++ ) {
	    scanf("%s", tmp ) ;
	    nms[i][j] = tmp ;
	}
    }

    for( int i=0; i<N; i++ ) {
	scanf("%d", &finA[i] ) ;
	finA[i] -- ;
	string tmp = max( nms[finA[i]][0], nms[finA[i]][1] ), tmp2 ;
	tmp2 = min( nms[finA[i]][0], nms[finA[i]][1] ) ;
	if( tmp<=act ) {
	    printf("NO\n" ) ;
	    return 0 ;
	}
	if( tmp2>act )
	    act = tmp2 ;
	else
	    act = tmp ;
    }

    printf("YES\n" ) ;
    
    return 0 ;
}
