#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;

int main() {
	long long N, K ;
	long long W ;

	cin >> N >> K ;
	W = (N/2) + (N%2) ;

	cout << ( (K<=W)? K*2-1 : (K-W)*2 ) << endl ;

	return 0 ;
}


