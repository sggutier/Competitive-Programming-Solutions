#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int mcho = 15000005 ;
int lim = 1000 ;

int main() {
	int N, A ;
	int arr[lim], sum = 0, k=0, tmp, vRes = (1<<30), res=0 ;
	int tot ;
	int ini, fin ;

	scanf("%d%d", &N, &A ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		sum += arr[i] ;
	}
	tot = sum ;

	sort( arr, arr+N ) ;

	for( int i=tot/arr[N-1]; i>=A; i-- ) {
		tmp = tot/i ;
		if( tmp<arr[N-1] )
			continue ;
		if( tot-tmp*i < vRes  ||  ( (tot-tmp*i)==vRes && i>res   ) ) {
			res = i ;
			vRes = tot - tmp*i ;
		}
	}

	for( int i=arr[N-1], w=N-1; i>0; i-- ) {
		for( ; w>=0 && arr[w]>i; sum-=arr[w], w--, k++ ) ;
		tmp = (sum/i + k ) ;
		if( tmp>=A ) {
			if( tot - tmp*i < vRes   ||   ( (tot-tmp*i)==vRes && tmp>res )  ) {
				res = tmp ;
				vRes = tot - tmp*i ;
			}
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}


