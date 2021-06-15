#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std ;

int main() {
	long long N ;
	int tam ;
	long long res ;
	
	cin >> N ;
	
	for( tam=1; ; tam++  ) {
		for( res=0LL; res<(1LL<<tam); res++   )  {
			long long w = 0LL ;
			int carg = 0 ;
			for( long long i=0LL, pot = 1LL; i<tam; i++, pot*=10LL ) {
				if( res&(1LL<<i)   ) {
					carg ++ ;
					w += 7LL*pot ;
				}
				else {
					carg -- ;
					w += 4LL*pot ;
				}
			}
			if( carg==0 && w>=N ) {
				cout << w << endl ;
				return 0 ;
			}
		}
	}
	
	return 0 ;
}

