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
using namespace std ;
const int lim = 100005 ;

int main() {
    int W = 0 ;
    
    while( scanf("%d", &W ) != EOF ) {
	int N, ty=0, res = 0 ;
	// cin >> N ;
	// N = i ;
	// cout << " -> " << N << endl ;
	N = W+1 ;
	while( N > 0 ) {
	    res += N ;
	    ty += N ;
	    N = ty/3 ;
	    ty %= 3 ;
	}
	// cout << "   "  << res << " " << ty << endl ;
	cout << res-1 << endl ;
    }
    
    return 0 ;
}
