#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cmath>
using namespace std ;

struct pto {
	double x, y, z ;
	pto() {
	}
	pto( double _x, double _y, double _z ) {
		x = _x ;
		y = _y ;
		z = _z ;
	}
};

double dis( double x, double y ) {
	return sqrt(x*x + y*y) ;
}

bool operator<( pto A, pto B ) {
	return A.z < B.z ;
}

int main() {
	int N ;
	pto arr[100005] ;
	double res = (1.0)*0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%lf%lf", &arr[i].x, &arr[i].y ) ;
		arr[i].z = acos( arr[i].x/dis(arr[i].x,arr[i].y) ) ;
		if( arr[i].y<0 )
			arr[i].z += M_PI ;
	}

	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		int w = i, k ;
		for( k=1; i+k<=N; k++ ) {
		double tmp = arr[(i+k)%N].z-arr[w].z ;
		if( tmp<0 )
			tmp += 2*M_PI ;
		if( tmp>0.00000001 )
			break ;
		}	
		if( i+k>N )
			break ;
		double tmp = arr[(i+k)%N].z-arr[w].z ;
		if( tmp<0 )
			tmp += 2*M_PI ;
		res = max( res, tmp ) ;
		//printf("%.9lf -> %.9lf\n",arr[i].z/(2*M_PI)*360.0, tmp/(2*M_PI)*360 ) ;
		i = i+k-1 ;
	}

	if( res>0.0000001 )
	res = 2*M_PI -res ;

	printf("%.9lf\n", res/(2*M_PI)*360.0 ) ;

	return 0 ;
}

