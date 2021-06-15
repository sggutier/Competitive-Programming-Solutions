#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string S ;
	int N ;
	int res = 0 ;
	int i, j ;
	
	cin >> S ;
	N = S.size() ;
	
	for( i=0; i<N; i=j ) {
		for( j=i+1; j<N && j<i+5 && ( !j || S[j]==S[j-1]  );   j++   )  ;
		res ++ ;
	}
	
	cout << res << endl ;

	return 0 ;
}
