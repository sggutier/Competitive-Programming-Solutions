#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;
const int lim = 1005 ;

int act = 0 ;
bool sta[lim] ;

int main() {
	int N, K ;
	char tmp[lim] ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<K; i++ ) {
		int tgt ;
		scanf("%s", tmp ) ;
		if( tmp[2]=='I' ) {
			scanf("%d", &tgt ) ;
			tgt -- ;
			if( sta[tgt] )
				act -- ;
			else
				act ++ ;
			sta[tgt] = !sta[tgt] ;
		}
		else {
			act = 0 ;
			for( int j=0; j<N; j++ ) 
				sta[j] = 0 ;
		}
		printf("%d\n", act ) ;
	}

	return 0 ;
}

