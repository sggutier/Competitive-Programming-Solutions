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

int main() {
	long long a, b, c ;
	long long res = 0LL ;

	cin >> a >> b ;
	while( b ) {
		res += a/b ;
		c = a%b ;
		a = b ;
		b = c ;
	}

	cout << res << endl ;

	return 0 ;
}


