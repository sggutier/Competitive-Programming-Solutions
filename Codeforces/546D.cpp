#include <bits/stdc++.h>
using namespace std;
const int limN = 5e6 + 5;

long long divCnt[limN];

void criba(int n = limN) {
    for(int i=2; i<n; i++) {
        divCnt[i] += divCnt[i-1];
        if(divCnt[i] != divCnt[i-1]) 
            continue;
        for(int j=i; j<n; j+=i) {
            int k = j ;
            while(k % i == 0) {
                divCnt[j] ++;
                k /= i;
            }
        }
    }
}

int main() {
    criba();
    int tc;
    int a, b ;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", divCnt[a] - divCnt[b]);
    }
}
