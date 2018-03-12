#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std ;
#define lim 1000005

int num2[lim], num5[lim] ;
int fact[lim] ;
int divM[10][10]  ;
char S[lim] ;

void precarg() {
	int i, tmp ;
	
	fact[0] = 1 ;
	
	for( i=1; i<lim; i++ ) {
		tmp = i ;
		num2[i] = num2[i-1] ;
		num5[i] = num5[i-1] ;
		fact[i] = fact[i-1] ;
		
		while( tmp % 2==0 ) {
			num2[i] ++ ;
			tmp /= 2 ;
		}
		while( tmp % 5==0 ) {
			num5[i] ++ ;
			tmp /= 5 ;
		}
		
		fact[i] *= tmp ;
		fact[i] %= 10 ;
	}
	
	for( i=0; i<10; i++ ) {
		tmp = 0 ;
		do { 
			divM[i][(tmp*i)%10] = tmp ;
			tmp ++ ;
		} while( (tmp*i)%10  )  ;
	}
}

void caso() {
	int N ;
	int r2=0, r5=0 ;
	int freq[26] ;
	int i, j ;
	int res = 1, w = 1 ;
	memset( freq, 0, sizeof(freq)  ) ;
	
	scanf("%s", S ) ;
	N = strlen( S ) ;
	
	for( i=0; i<N; i++ ) {
		freq[ S[i] - 'a' ] ++ ;
	}
	
	r2 += num2[N] ;
	r5 += num5[N] ;
	res = fact[N] ;
	for( i=0; i<26; i++ ) {
		r2 -= num2[ freq[i] ] ;
		r5 -= num5[ freq[i] ] ;
		w *= fact[ freq[i] ] ;
		w %= 10 ;
	}
	j = min( r2, r5 ) ;
	r2 -= j ;
	r5 -= j ;
	
	res = divM[w][res] ;
	for( i=0; i<r2; i++ ) {
		res *= 2 ;
		res %= 10 ;
	}
	for( i=0; i<r5; i++ ) {
		res *= 5 ;
		res %= 10 ;
	}
	
	printf("%d\n", res ) ;
	
}

int main() {
	precarg() ;
	int T ;
	
	scanf("%d", &T ) ;
	while( T ) {
		caso() ;
		T -- ;
	}
	
	return 0 ;
}
