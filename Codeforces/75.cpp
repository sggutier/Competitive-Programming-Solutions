#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 2000000

int main() {
	int N ;
	
	cin >> N ;
	
	for( int i=1; i*i<=N; i++ ) {
		for( int j=i; j*j+i*i<=N; j++ ) {
			int k = j*j + i*i, w ;
			w = int(sqrt(k)) ;
			if( k & w*w==k ) {
				res[i*i+j*j+k]
			}
		}
	}
	
	return 0 ;
}
