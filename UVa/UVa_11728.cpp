#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 ;

int divSum[limN+1];
int minW[limN+1];

void precarga(int n = limN) {
    for(int i=0; i<=n; i++)
        minW[i] = -1;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i)
            divSum[j] += i;
        if(divSum[i]<=n) {
            minW[divSum[i]] = i;
        }
    }
}

int main() {
    precarga();
    int n, tc=0;
    while(scanf("%d", &n)!=EOF && n)
        printf("Case %d: %d\n", ++tc, minW[n]);
}
