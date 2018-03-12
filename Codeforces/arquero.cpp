#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second

int main() {
		long long N ;
        long long res=0LL ;
		long long hor, foo, hor2, foo2 ;
		long long lim ;

        cin >> N ;
		lim = N ;

        if( N<=2 ) {
            printf("1\n" ) ;
            return 0 ;
        }

		N = N*N*4 ;

		for( int i=-lim; i<=lim; i++ ) {
			hor = 3LL*abs(i) + 1LL ;
			hor = hor*hor ;
			hor2 = 3LL*abs(i) + 2LL ;
			hor2 = hor2*hor2 ;
			int ini=0, fin=lim ;

			if( i%2==0 )
				foo = 1 ;
			else
				foo = 0 ;
			foo2 = 1-foo ;

			while( ini<fin ) {
				int piv = (ini+fin)/2 + 1 ;
				if( 3LL*(2LL*piv+foo)*(2LL*piv+foo) + hor <= N && 3LL*(2LL*piv-foo2)*(2LL*piv-foo2) + hor2 <=N ) 
					ini = piv ;
				else
					fin = piv-1 ;
			}

			if( 3LL*(2LL*ini+foo)*(2LL*ini+foo) + hor > N   &&    3LL*(2LL*ini-foo2)*(2LL*ini-foo2) + hor2 > N ) 
				continue ;

			res += ini*2 ;
			if( i%2==0 )
				res ++ ;
		}

		cout << res << endl ;

        return 0 ;
}

