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
#include <stack>
using namespace std ;

int main() {
	int N, S ;
	char arr[100005] ;
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", arr ) ;
		S = strlen(arr) ;
		int ultL = -1, ultR=-1, T[2] = { -1, -1 } ;
		int k = 1 ;

		for( int i=0; i<S; i++ ) {
			arr[i] -= 'A' ;
			if( T[arr[i]]==-1 ) {
				T[arr[i]] = i ;
			}
			else {
				if( ultL>T[arr[i]] || T[arr[i]]>ultR ) {
					ultL = T[arr[i]] ;
					ultR = i ;
					T[arr[i]] = -1 ;
				}
				else {
					k = 0 ;
					break ;
				}
			}
		}

		if( T[0]!=-1 || T[1]!=-1 )
			k = 0 ;

		res += k ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}

