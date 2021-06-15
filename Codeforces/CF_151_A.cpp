#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N;
	int K, L ;
	int c, d ;
	int p, nl, np ;
	int res = (1<<30) ;
	
	scanf("%d", &N ) ;
	scanf("%d%d", &K, &L ) ;
	scanf("%d%d", &c, &d ) ;
	scanf("%d%d%d", &p, &nl, &np ) ;
	
	res = min( res, (K*L)/nl ) ;
	res = min( res, c*d ) ;
	res = min( res, p/np ) ;
	
	printf("%d\n", res/N ) ;
	
	return 0 ;
}

