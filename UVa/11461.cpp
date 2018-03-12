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
    int A, B ;

    while( scanf("%d%d", &A, &B)!=EOF  and  (A or B)  ) {
	int x= int( ceil(sqrt(A*1.0)) ), y=int( floor(sqrt(B*1.0)) ) ;
	printf("%d\n", max(0, y-x+1) ) ;
    }
    
    return 0 ;
}
