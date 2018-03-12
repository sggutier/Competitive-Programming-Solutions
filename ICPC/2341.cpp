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
const int inf = (1<<30) ;

void desp( string S, string &res, int &numRes ) {
	string K ;
	numRes = -inf ;
	for( int i=0; i<S.size(); i++ ) {
		if( S[i]==' ' ) {
			K = S.substr( i+1, S.size()-i-1 ) ;
			sscanf( K.c_str(), "%d", &numRes ) ;
			break ;
		}
		res += S[i] ;
	}
}

int main() {
	int N, M ;
	map <string,int> resp ;
	char tmp[1000] ;
	scanf("%d%d", &N, &M ) ;
	gets(tmp) ;
	for( int i=0; i<N; i++ ) {
		string S ;
		int K ;
		gets( tmp ) ;
		desp( tmp, S, K ) ;
		resp[S] = K ;
	}
	for( int i=0; i<M; i++ ) {
		string S ;
		int K ;
		gets( tmp ) ;
		desp( tmp, S, K ) ;
		if( K==-inf ) 
			printf("not found\n" ) ;
		else
			printf("%s\n", (resp[S]==K)? "ok" : "wrong" ) ;
	}

	return 0 ;
}


