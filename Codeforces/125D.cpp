#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 30005 ;

int N, A, B ;
int arr[lim], le[lim], ro[lim] ;

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;

	for( int w=0; w<5 && w<N; w++ ) {
		int dif = arr[w]-arr[0], dif2 ;

		A = 1 ;
		B = 0 ;
		if( w )
			A ++ ;
		le[0] = arr[0] ;
		le[1] = arr[w] ;
		
		for( int i=1; i<N; i++ ) {
			if( i==w )
				continue ;
			if( w && le[A-1]+dif == arr[i] ) {
				if( i+1<N && B>=2 && ro[B-1]+dif2==arr[i] && arr[i]+dif2==arr[i+1] )
					ro[B++] = arr[i] ;
				else
					le[A++] = arr[i] ;
			}
			else {
				if( B==1 )
					dif2 = arr[i] - ro[0]  ;
				if( B<2 || ro[B-1]+dif2==arr[i] )
					ro[B++] = arr[i] ;
				else
					break ;
			}
		}

		if( A+B==N && B ) {
			for( int i=0; i<A; i++ ) 
				printf("%d ", le[i] ) ;
			printf("\n" ) ;
			for( int i=0; i<B; i++ ) 
				printf("%d ", ro[i] ) ;
			printf("\n" ) ;
			return 0 ;
		}
	}
	for( int w=1; w<5 && w<N; w++ ) {
		int dif = arr[w]-arr[1], dif2 ;

		A = 1 ;
		B = 0 ;
		if( w )
			A ++ ;
		le[0] = arr[1] ;
		le[1] = arr[w] ;

		for( int i=0; i<N; i++ ) {
			if( i==w || i==1 )
				continue ;
			if( w!=1 && le[A-1]+dif == arr[i] ) {
				if( i+1<N && B>=2 && ro[B-1]+dif2==arr[i] && arr[i]+dif2==arr[i+1] )
					ro[B++] = arr[i] ;
				else
					le[A++] = arr[i] ;
			}
			else {
				if( B==1 )
					dif2 = arr[i] - ro[0]  ;
				if( B<2 || ro[B-1]+dif2==arr[i] )
					ro[B++] = arr[i] ;
				else
					break ;
			}
		}

		if( A+B==N && B ) {
			for( int i=0; i<A; i++ ) 
				printf("%d ", le[i] ) ;
			printf("\n" ) ;
			for( int i=0; i<B; i++ ) 
				printf("%d ", ro[i] ) ;
			printf("\n" ) ;
			return 0 ;
		}
	}

	printf("No solution\n" ) ;

	return 0 ;
}


