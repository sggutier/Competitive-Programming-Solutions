#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std ;

int val[300] ;

int repoker( char Q[] ) {
	for( int i=1; i<5; i++ )
		if( Q[i]!=Q[i-1] )
			return 0 ;
	return 9000 + Q[0] ; // the repoker is over 9000!!!!!
}

int poker( char Q[] ) {
	for( int j=0; j<2; j++ ) {
		int i ;
		for( i=j+1; i<j+4; i++ )
			if( Q[i]!=Q[i-1] )
				break ;
		if( i==j+4 )
			return 7000 + Q[j] ;
	}
	return 0 ;
}

int tercia( char Q[] ) {
	for( int j=0; j<3; j++ ) {
		int i ;
		for( i=j+1; i<j+3; i++ )
			if( Q[i]!=Q[i-1] )
				break ;
		if( i==j+3 )
			return 3000 + Q[j] ;
	}
	return 0 ;
}

int par( char Q[] ) {
	for( int j=0; j<4; j++ ) {
		int i ;
		for( i=j+1; i<j+2; i++ )
			if( Q[i]!=Q[i-1] )
				break ;
		if( i==j+2 )
			return 1000 + Q[j] ;
	}
	return 0 ;
}

int doPar( char Q[] ) {
	for( int j=0; j<3; j++ ) {
		int i ;
		for( i=j+1; i<j+2; i++ )
			if( Q[i]!=Q[i-1] )
				break ;
		if( i==j+2 ) {
			for( int a=i+1; a<4; a++ ) {
				int b ;
				for( b=a+1; b<a+2; b++ )
					if( Q[b]!=Q[b-1] )
						break ;
				if( b==a+2 ) {
					return 2000 + max( Q[a], Q[j] ) ;
				}
			}
		}
	}
	return 0 ;
}

int maxArr( char Q[] ) {
	int res = 0 ;
	for( int i=0; i<5; i++ )
		res = max( res, int(Q[i])  );
	return res ;
}

int escalera( char Q[] ) {
	if( Q[0]==2 && Q[0]==3 && Q[0]==4 && Q[0]==5 && Q[0]==14 )
		return 4005 ;
	for( int i=1; i<5; i++ )
		if( Q[i]!=Q[i-1]+1 )
			return 0 ;
	return 4000 + Q[4] ;
}

int full( char Q[] ) {
	return 15*(tercia(Q)-3000) + (par(Q)-1000) ;
}

int main() {
	int N ;
	pair <int,string> res[3000] ;
	
	for( int i=2; i<10; i++ )
		val[i+'0'] = i ;
	val['J'] = 11 ;
	val['Q'] = 12 ;
	val['K'] = 13 ;
	val['A'] = 14 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		char A[5], Q[5], B[5] ;
		int W=0, ult=-1 ;
		
		cin >> res[i].second ;
		for( int j=0; j<5; j++ ) {			
			cin >> A ;
			Q[j] = val[A[0]] ;
			if( A[0]=='1' && A[1]=='0' )
				Q[j] = 10 ;
			cin >> B ;
			W = B[0] ;
			if( j==0 )
				ult = W ;
			if( W!=ult )
				ult = -1 ;
		}
		
		ult = (ult!=-1) ;
		W = 0 ;
		
		sort( Q, Q+5 ) ;
		/*for( int j=0; j<5; j++ )
			cout << int(Q[j]) << " " ;
		cout << endl ;*/
		W = max( W, repoker(Q) ) ;
		W = max( W, (escalera(Q)!=0)*ult*8000 +maxArr(Q) ) ;
		W = max( W, poker(Q) ) ;
		W = max( W, (par(Q)!=0)*(tercia(Q)!=0)*6000 +  (par(Q)!=0)*(tercia(Q)!=0)*full(Q)  ) ;
		W = max( W, ult*5000 + maxArr(Q) ) ;
		W = max( W, escalera(Q) ) ;
		W = max( W, tercia(Q) ) ;
		W = max( W, doPar(Q) ) ;
		W = max( W, par(Q) ) ;
		W = max( W, maxArr(Q) ) ;
		W = W*1000 + maxArr(Q) ;
		res[i].first = W ;
	}
	
	sort( res, res+N ) ;
	for( int i=0; i<N; i++ )
		//cout << res[i].second << " " << res[i].first << endl ;
		cout << res[i].second << endl ;
		
	return 0 ;
}
