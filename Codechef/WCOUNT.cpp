#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 510
#define mod 1000000007LL

int P=0 ;
int primos[lim] ;

void criba() ;
void caso() ;
void facto( int N, int arr[], int sum ) ;

int main() {
	criba() ;
	int T ;
	
	// Para cada caso de prueba ejecutar la funcion que lo hace
	for( scanf("%d", &T );  T;  T-- ) 
		caso() ;
	
	return 0 ;
}

void criba() {
	bool comp[lim] ;
	memset( comp, 0, sizeof(comp)  ) ;
	
	for( int i=2; i<lim; i++ ) {
		if( comp[i] )
			continue ;
		primos[P++] = i ;
		for( int j=i*i; j<lim; j+=i )
			comp[j] = 1 ;
	}
}

void caso() {
	int N ;
	char S[lim] ;
	int comp[lim], rep[lim] ;
	long long res = 1LL ;
	
	//Leer e inicialisar madrolas
	scanf("%s", S ) ;
	N = strlen(S) ;
	memset( comp, 0, sizeof(comp)  ) ;
	memset( rep, 0, sizeof(rep)  ) ;
	for( int i=0; i<N; i++ )
		rep[ S[i] ] ++ ;
	
	//Factorizar la longitud de S en primos y registrar los exponentes 
	// en un arreglo
	facto( N, comp, 1 ) ;
	//Factorizar cada grupo de letras iguales en primos y quitarle los
	//exponentes al arreglo anterior
	for( int i=0; i<lim; i++ ) {
		if( rep[i] ) 
			facto( rep[i], comp, -1 ) ;
	}
	
	//Calcular el numero de permutaciones mientras se saca modulo en 
	//base a el numero compuesto antes calculado
	for( int i=0; i<P; i++ )
		for( ; comp[i]; comp[i]-- )
			res = ( res*primos[i] )%mod ;
			
	//Imprimir
	printf("%d\n", int(res) ) ;
}

void facto( int N, int arr[], int sum ) {
	for( int k=1; k<=N; k++ ) {
		for( int i=0, a; i<P && primos[i]<=k; i++ ) {
			a = k ;
			while( a%primos[i]==0 ) {
				a /= primos[i] ;
				arr[i] += sum ;
			}
		}
	}
}
