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
using namespace std ;
const int lim = 100005 ;

int N ;

int main() {
    long long res = 0LL ;
    int sum = 0 ;
    
    scanf("%d", &N );
    for( int i=1; i<=N; i++ ) {
	int tmp ;
	scanf("%d", &tmp ) ;
	if( tmp )
	    sum ++ ;
	else
	    res += sum ;
    }

    cout << res << endl ;
    
    return 0 ;
}
