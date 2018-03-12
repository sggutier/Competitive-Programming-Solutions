#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N, dia ;

    cin >> N ;

    dia = ((N-1)*N)/2 - N ;

    printf("%d\n", (dia*(N-3) )/2  ) ;

    return 0 ;
}
