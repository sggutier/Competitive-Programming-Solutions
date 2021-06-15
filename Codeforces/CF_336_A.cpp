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
#define par pair<int,int>
#define x first
#define y second

int main() {
	int A, B, x, y ;
	par rA, rB ;

	cin >> A >> B ;

	x = abs(A), y=abs(B) ;

	rA = par( 0, (x+y)*(y/B)  ) ;
	rB = par( (x+y)*(x/A), 0  ) ;

	if( rA>rB )
		swap( rA, rB ) ;

	printf("%d %d %d %d\n", rA.x, rA.y, rB.x, rB.y ) ;

	return 0 ;
}


