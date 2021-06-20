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
#define ull unsigned long long
const ull bas = 3ULL ;
const ull bas2 = 5ULL ;
const int lim = 100000 ;

string iniA, iniB, finA, finB, conc, iniC, finC ;
ull crgA, crgB, crgC ;
ull ha, ha2, pot[lim + 5], pot2[lim + 5], crg[4*lim + 5], crg2[4*lim+5] ;
ull res ;

void precalc() {
	pot[0] = 1ULL ;
	pot2[0] = 1ULL ;
	for( int i=1; i<=lim; i++ ) {
		pot[i] = pot[i-1]*bas ;
		pot2[i] = pot2[i-1]*bas2 ;
	}
}

string norm( string S ) {
	for( int i=0; i<S.size(); i++ ) 
		S[i] += '0' ;
	return S ;
}

ull rec( string &S, ull ha, ull ha2, int K ) {
	int N = S.size() ;
	ull tmp, ans=0ULL, tmp2 ;

	crg[0] = S[0] + 0ULL ;
	crg2[0] = S[0] + 0ULL ;
	if( K==1 && crg[0]==ha ) {
		ans ++ ;
	}
	for( int i=1; i<N; i++ ) {
		crg[i] = crg[i-1]*bas + S[i] ;
		crg2[i] = crg2[i-1]*bas2 + S[i] ;
		if( i>=K )  {
			tmp = crg[i] - crg[i-K]*pot[K] ;
			tmp2 = crg2[i] - crg2[i-K]*pot2[K] ;
		}
		else {
			tmp = crg[i] ;
			tmp2 = crg2[i] ;
		}
		if( i>=K-1 ) {
			if( tmp==ha && tmp2==ha2 )
				ans ++ ;
		}
	}

	return ans ;
}

ull caso( int N ) {
	int K, i ;
	char tmp[lim + 5] ;
	ull lol, wut ;

	ha = 0ULL ;
	ha2 = 0ULL ;
	res = 0ULL ;
	iniA = "0" ;
	iniB = "1" ;
	iniA[0] -= '0' ;
	iniB[0] -= '0' ;

	scanf("%s", tmp ) ;
	K = strlen(tmp) ;

	if( N==0 ) {
		if( tmp[0]=='0' && K==0 )
			return 1ULL ;
		else
			return 0ULL ;
	}
	if( N==1 ) {
		if( tmp[0]=='1' && K==0 )
			return 1ULL ;
		else
			return 0ULL ;
	}

	for( i=0; i<K; i++ ) 
		ha = ha*bas + (tmp[i]-'0') ;
	for( i=0; i<K; i++ ) 
		ha2 = ha2*bas2 + (tmp[i]-'0') ;

	for( i=2; i<=N && iniA.size()<2*K; i++ )  {
		conc = iniB + iniA ;
		iniA = iniB ;
		iniB = conc ;
	}

	if( i>N ) {
		return rec( iniB, ha, ha2, K ) ;
	}

	crgA = rec( iniA, ha, ha2, K ) ;
	crgB = rec( iniB, ha, ha2, K ) ;

	finA = iniA.substr( iniA.size()-K, K ) ;
	finB = iniB.substr( iniB.size()-K, K ) ;
	iniA = iniA.substr( 0, K ) ;
	iniB = iniB.substr( 0, K ) ;

	conc = finB.substr( 1, finB.size()-1 )  +  iniA.substr( 0, iniA.size()-1 )  ;
	crgC = rec( conc, ha, ha2, K ) + crgA + crgB ;

	i ++ ;
	if( i>N ) {
		return crgC ;
	}

	crgA = crgB ;
	crgB = crgC ;

	conc = finA.substr( 1, finA.size()-1 )  +  iniB.substr( 0, iniB.size()-1 )  ;
	lol = rec( conc, ha, ha2, K ) ;
	conc = finB.substr( 1, finB.size()-1 )  +  iniB.substr( 0, iniB.size()-1 )  ;
	wut = rec( conc, ha, ha2, K ) ;

	for( ; i<=N; i++, swap( lol, wut )   ) {
		crgC = lol + crgA + crgB ;
		crgA = crgB ;
		crgB = crgC ;
	}

	return crgB ;
}

int main() {
	precalc() ;

	int N ;

	for( int t=1; scanf("%d", &N) != EOF;  t++  ) {
		printf("Case %d: %llu\n", t, caso(N) ) ;
	}

	return 0 ;
}


