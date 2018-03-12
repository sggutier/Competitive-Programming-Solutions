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

map < int, list<int> > rep ;

int main() {
	int N, K ;
	int res = 0 ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		rep[tmp].push_back(i) ;
	}

	for( map < int, list<int> > :: iterator IT = rep.begin();  IT!=rep.end(); IT++      )    {
		list<int> *act = &(IT -> s) ;
		int w = 1 ;

		for( list<int>::iterator pos=(*act).begin(), prev=pos;  pos!=(*act).end();   pos++, w++ ) {
			while( (*pos)-(*prev)+1-w<=K ) {
				prev ++ ;
				w -- ;
			}
			res = max( res, w ) ;
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}


