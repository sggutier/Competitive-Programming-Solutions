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
const int lim = 1000005 ;

map <int,int> cnt ;
int arr[lim] ;

int main() {
    int tmp ;
    int K = 0 ;

    while( scanf("%d",&tmp)!=EOF ) {
	if( cnt.find(tmp)==cnt.end() ) {
	    cnt[tmp] = 0 ;
	    arr[K++] = tmp ;
	}
	cnt[tmp] ++ ;
    }

    for( int i=0; i<K; i++ )
	printf("%d %d\n", arr[i], cnt[arr[i]] ) ;
    
    return 0 ;
}
