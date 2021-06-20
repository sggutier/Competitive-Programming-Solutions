#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int W ;
int res = 0 ;
int arr[6], esq[6] ;
bool usd[10] ;

void prueba( int pos ) {
	if( pos==4 ) {
		int q = 1000, i, k=0 ;
		
		for( i=0; i<10; i++ ) 
			if( !usd[i] ) 
				break ;
		if( arr[0] + arr[4] + i != W )
			return ;
		
		esq[4] = i ;
		for( int i=0; i<5; i++ )  {
			q = min( q, esq[i]*100 + arr[i]*10 + arr[(i+1)%5] ) ;
			if( esq[i]==9 )
				k += 2 ;
			else
				k ++ ;
			if( arr[i]==9 )
				k += 4 ;
			else
				k += 2 ;
		}
		
		if( k==16 )
			res = max( res, q ) ;
		cout << k << "   " ;
		for( int i=0; i<5; i++ ) 
			printf("%d %d %d;   ", esq[i]+1, arr[i]+1, arr[(i+1)%5]+1 ) ;
		printf("\n" ) ;
		
		return ;
	}
	
	for( esq[pos]=0; esq[pos]<10; esq[pos]++ ) {
		if( usd[esq[pos]] )
			continue ;
		usd[esq[pos]] = 1 ;
		arr[pos+1]=W-(arr[pos]+esq[pos]);
		if( arr[pos+1]>=0 &&  arr[pos+1]<=9  && !usd[arr[pos+1]] ) {
			usd[arr[pos+1]] = 1 ;
			prueba( pos+1 ) ;
			usd[arr[pos+1]] = 0 ;
		}
		usd[esq[pos]] = 0 ;
	}
}

void fin( int pos ) {
	if( pos==4 ) {		
		int q = 1000, i, k=0 ;
		
		for( i=0; i<10; i++ ) 
			if( !usd[i] ) 
				break ;
		if( arr[0] + arr[4] + i != W )
			return ;
		
		esq[4] = i ;
		for( int i=0; i<5; i++ )  {
			q = min( q, esq[i]*100 + arr[i]*10 + arr[(i+1)%5] ) ;
			if( esq[i]==9 )
				k += 2 ;
			else
				k ++ ;
			if( arr[i]==9 )
				k += 4 ;
			else
				k += 2 ;
		}
		
		if( res!=q )
			return ;
		
		cout << k << "   " ;
		printf("--->>>  " ) ;	
		for( int i=0; i<5; i++ ) 
			printf("%d %d %d;   ", esq[i]+1, arr[i]+1, arr[(i+1)%5]+1 ) ;
		printf("\n" ) ;
		
		return ;
	}
	
	for( esq[pos]=0; esq[pos]<10; esq[pos]++ ) {
		if( usd[esq[pos]] )
			continue ;
		usd[esq[pos]] = 1 ;
		arr[pos+1]=W-(arr[pos]+esq[pos]);
		if( arr[pos+1]>=0 &&  arr[pos+1]<=9  && !usd[arr[pos+1]] ) {
			usd[arr[pos+1]] = 1 ;
			fin( pos+1 ) ;
			usd[arr[pos+1]] = 0 ;
		}
		usd[esq[pos]] = 0 ;
	}
}

int main() {
	
	for( W=0; W<30; W++ ) {
		for( arr[0]=0; arr[0]<10; arr[0]++ ) {
			usd[arr[0]] = 1 ;
			prueba(0) ;
			usd[arr[0]] = 0 ;
		}
	}
	cout << res << endl ;
	for( W=0; W<30; W++ ) {
		for( arr[0]=0; arr[0]<10; arr[0]++ ) {
			usd[arr[0]] = 1 ;
			fin(0) ;
			usd[arr[0]] = 0 ;
		}
	}
	
	return 0 ;
}
