#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

int N = 0 ;
double ini[105][2], fin[105][2] ;

int main() {
    char tmp[5] ;
    double pts[2] ;
    double eps = 1.0e-9 ;
    int K = 0 ;

    while( scanf("%s",tmp)!=EOF && tmp[0]!='*' ) {
	scanf("%lf%lf%lf%lf", &ini[N][0], &fin[N][1], &fin[N][0], &ini[N][1] ) ;
	N ++ ;
    }
    while( scanf("%lf%lf", &pts[0], &pts[1] )!=EOF && (fabs(9999.9-pts[0])>eps || fabs(9999.9-pts[1])>eps) )  {
	K ++ ;
	int cnt = 0 ;
	for( int i=0; i<N; i++ )  {
	    int a = -2 ;
	    for( int j=0; j<2; j++ ) 
		if( pts[j]>ini[i][j] && pts[j]<fin[i][j] )
		    a ++ ;
	    if( !a ) {
		cnt ++ ;
		printf("Point %d is contained in figure %d\n", K, i+1 ) ;
	    }
	}
	if( cnt==0 )
	    printf("Point %d is not contained in any figure\n", K  ) ;
    }
    
    return 0 ;
}
