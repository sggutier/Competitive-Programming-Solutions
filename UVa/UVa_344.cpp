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
const int lim = 101 ;

int cntR[lim][5] ;
char letras[] = "ivxlc" ;

void cntNums( int *nums, int N ) ;
    

int main() {
    int N ;
    
    for( int i=1; i<lim; i++ ) {
	cntNums( cntR[i], i ) ;
	for( int j=0; j<5; j++ )
	    cntR[i][j] += cntR[i-1][j] ;
    }

    while( scanf("%d",&N)!=EOF  and N!=0  ) {
	printf("%d:", N ) ;
	for( int i=0; i<5; i++ ) {
	    if( i )
		printf("," ) ;
	    printf(" %d %c", cntR[N][i], letras[i] ) ;
	}
	printf("\n" ) ;
    }
    
    return 0 ;
}

void cntNums( int *nums, int N ) {
    for( int i=0; i<5; i++ )
	nums[i] = 0 ;
    if( N>=100 ) {
	nums[4] += N/100 ;
	N %= 100 ;
    }
    if( N>=90 ) {
	nums[4] += N/90 ;
	nums[2] += N/90 ;
	N %= 90 ;
    }
    if( N>=50 ) {
	nums[3] += N/50 ;
	N %= 50 ;
    }
    if( N>=40 ) {
	nums[3] += N/40 ;
	nums[2] += N/40 ;
	N %= 40 ;
    }
    if( N>=10 ) {
	nums[2] += N/10 ;
	N %= 10 ;
    }
    if( N>=9 ) {
	nums[2] += N/9 ;
	nums[0] += N/9 ;
	N %= 9 ;
    }
    if( N>=5 ) {
	nums[1] += N/5 ;
	N %= 5 ;
    }
    if( N>=4 ) {
	nums[1] += N/4 ;
	nums[0] += N/4 ;
	N %= 4 ;
    }
    nums[0] += N ;
}
