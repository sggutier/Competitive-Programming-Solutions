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
    int T ;
    int a, b ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ){
	scanf("%d%d", &a, &b ) ;
	printf("%d\n", (int (ceil((a-2)/3.0))) * (int (ceil((b-2)/3.0)) )  ) ;
    }
    
    return 0 ;
}
