#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int N, M ;

    scanf("%d%d", &N, &M ) ;
    N = min( N, M ) ;
    printf("%s\n", N%2==0? "Malvika":"Akshat" ) ;
    
    return 0 ;
}
