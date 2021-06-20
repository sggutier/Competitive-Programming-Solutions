#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

struct num {
    int tam ;
    char arr[205] ;
    num() {
	tam = 1 ;
	memset( arr, 0, sizeof(arr) ) ;
	arr[0] = '0' ;
    }
    void imprime() {
	reverse( arr, arr+tam ) ;
	printf("%s\n", arr ) ;
	reverse( arr, arr+tam ) ;
    }
};

num operator + ( num A, num B ) {
    int crg = 0, K=max( A.tam, B.tam ) ;
    num res ;
    for( int i=0; i<K; i++ ) {
	if( A.arr[i] )
	    crg += A.arr[i]-'0' ;
	if( B.arr[i] )
	    crg += B.arr[i]-'0' ;
	res.arr[i] = crg%10 + '0'  ;
	crg /= 10 ;
    }
    while( crg) {
	res.arr[K++] = crg%10 + '0' ;
	crg /= 10 ;
    }
    res.tam = K ;
    return res ;
}

int main() {
    num res, tmp ;
    while( scanf("%s", tmp.arr )!=EOF ) {
	tmp.tam = strlen(tmp.arr) ;
	if( tmp.tam==1 && tmp.arr[0]=='0' )
	    break ;
	reverse( tmp.arr, tmp.arr + tmp.tam ) ;
	res = res + tmp ;
	tmp = num() ;
    }
    res.imprime() ;
    return 0 ;
}
