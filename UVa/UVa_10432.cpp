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

int main() {
    double r, n ;

    while( scanf("%lf%lf", &r, &n ) !=EOF  ) {
	double a = M_PI/n*2.0 ;
	printf("%.3lf\n", n*( sin(a)*r*r/2.0 )  ) ;
    }
    
    return 0 ;
}
