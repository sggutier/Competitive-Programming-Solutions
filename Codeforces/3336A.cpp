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
	long long A, B, x, y ;

	cin >> A >> B ;

	x = abs(A), y=abs(B) ;

	cout << "0 " << (x+y)*(x/A) << endl ;
	cout << (x+y)*(y/B) << " 0" << endl ;

	return 0 ;
}


