#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 100005

int main() {
	int N, ant=-(1<<30), act ;
	long long w=0LL, res = 0LL ;
	
	scanf("%d",&N ) ;
	while ( N ) {
		N -- ;
		scanf("%d",&act ) ;
		if( act==ant ) 
			w ++ ;
		else 
			w = 1LL ;
		res += w ;
		ant = act ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
