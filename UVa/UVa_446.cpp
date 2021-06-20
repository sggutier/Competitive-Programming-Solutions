#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

int hDectoI( char *S ) {
    int N = strlen(S) ;
    int res = 0 ;

    for( int i=N-1, pot=1; i>=0; i--, pot*=16 )
	res += (isdigit(S[i])? S[i]-'0' : S[i]-'A'+10) * pot ;

    return res ;
}

void printI( int A ) {
    for( int i=12; i>=0; i-- )
	printf("%c", ((1<<i) & A)? '1':'0' ) ;
}

void caso() {
    char S[lim], K[lim] ;
    int A, B ;

    scanf("%s", S ) ;
    A = hDectoI(S) ;
    scanf("%s", K ) ;
    scanf("%s", S ) ;
    B = hDectoI(S) ;

    printI(A) ;
    printf(" %c ", K[0] ) ;
    printI(B) ;
    printf(" = %d\n", (K[0]=='+')? A+B : A-B ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
