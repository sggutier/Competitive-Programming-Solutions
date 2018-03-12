#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int resMax = -(1<<30), resMin = -resMax ;
    int N ;

    while( scanf("%d", &N) != EOF  )  {
        resMax = max( resMax, N ) ;
        resMin = min( resMin, N ) ;
    }

    printf("%d\n", resMax + resMin ) ;

    return 0 ;
}
