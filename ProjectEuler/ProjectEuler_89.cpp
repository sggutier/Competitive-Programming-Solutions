#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std ;

map <char,int> val ;

int escrb( int N ) {
				//  0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	int arr[10] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 } ;
	int res = 0 ;
	
	if( N>=1000 ) {
		res += N/1000 ;
		N %= 1000 ;
	}
	
	while( N ) {
		res += arr[N%10] ;
		N /= 10 ;
	}
	return res ;
}

int num( string S ) {
	int ult = 1000000 ;
	int res = 0 ;
	
	for( int i=0; i<S.size(); i++ ) {
		if( val[S[i]]>ult ) 
			res -= 2*ult ;
		res += val[S[i]] ;
		ult = val[S[i]] ;
	}
	
	return res ;
}

int main() {	
	freopen( "roman.txt", "r", stdin ) ;
	
	val['I'] = 1 ;
	val['V'] = 5 ;
	val['X'] = 10 ;
	val['L'] = 50 ;
	val['C'] = 100 ;
	val['D'] = 500 ;
	val['M'] = 1000 ;
	
	int N, res=0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		string S ;	
		cin >> S ;	
		res += int(S.size())-escrb(num(S)) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
