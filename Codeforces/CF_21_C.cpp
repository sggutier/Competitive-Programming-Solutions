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
const int lim = 100005 ;

int N ;
int arr[lim], rep[lim] ;
map <long long,long long> marc ;

int main() {
	long long sum=0LL, carg=sum ;
	long long res=0LL ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )  {
		scanf("%d", &arr[i] ) ;
		sum += arr[i] ;
	}

	for( int i=0; i+1<N; i++ ) {
		carg += arr[i] ;
		if( i && carg%2LL==0LL ) {
			long long mit=carg/2 ;
			if( mit*3LL==sum )
				res += marc[mit] ;
		}
		if( marc.find(carg)==marc.end()  )
			marc[carg] = 0LL ;
		marc[carg] ++ ;
	}

	cout << res << endl ;

	return 0 ;
}


