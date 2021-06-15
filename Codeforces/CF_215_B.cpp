#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;
#define lim 5005

int main() {
	double R=-(1<<30)*1.0, res=R ;
	int N, M ;
	double arr[lim], arr2[lim], A, B ;
	
	cin >> N ;
	for( int i=0, tmp; i<N; i++ ) {
		cin >> tmp ;
		R = max( R, tmp*1.0 ) ;
	}
	cin >> N ;
	for( int i=0; i<N; i++ ) 
		cin >> arr[i] ;
	cin >> M ;
	for( int i=0; i<M; i++ ) 
		cin >> arr2[i] ;
	cin >> A >> B ;	
	
	R *= R ;
	for( int i=0; i<N; i++ ) 
		for( int j=0; j<M; j++ ) 
			res = max( res, sqrt( ( B*arr[i]*R )/(  A*arr2[j] + B*arr[i]  ) )    ) ;
	
	printf("%0.9lf\n", res ) ;
	
	return 0 ;
}
