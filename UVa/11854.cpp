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
    int arr[3] ;

    while( scanf("%d%d%d", &arr[0], &arr[1], &arr[2] )!=EOF  and (arr[0] or arr[1] or arr[2])  ) {
	sort( arr, arr+3 ) ;
	printf("%s\n", arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]?
	       "right" : "wrong" ) ;
    }
    
    return 0 ;
}
