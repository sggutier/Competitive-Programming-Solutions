#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int main() {
	int N ;
	double W[lim], carg=1.0*0, sumT=1.0*0 ;
	double dis[lim] ;
	double res = 1.0*0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		cin >> W[i] ;
	}
	
	dis[N-1] = 1.0*0 ;
	for( int i=N-2; i>=0; i-- ) {
		sumT += W[i+1] ;
		dis[i] = (1.0-(carg/sumT)) / W[i+1] ;
		carg += W[i+1]*dis[i] ;
		res += dis[i] ;
	}
	
	printf("%.9lf\n", res ) ;
	
	return 0 ;
}
