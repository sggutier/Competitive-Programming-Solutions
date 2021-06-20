#include <bits/stdc++.h>
using namespace std;

int testCase(long long k) {
    int ini=0, fin=1e8;
    while(ini<fin) {
        long long piv = (ini+fin)/2 ;
        if( (piv*(piv-3))/2 < k)
            ini = piv + 1;
        else
            fin = piv;
    }
    return ini;
}

int main() {
    long long k;
    int tc = 0;
    while(scanf("%lld", &k)!=EOF && k){
        printf("Case %d: %d\n", ++tc, testCase(k));
    }
}
