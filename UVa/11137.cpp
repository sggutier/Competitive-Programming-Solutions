#include <bits/stdc++.h>
using namespace std;
const int limC = 21;
const int limN = 1e4;

long long ans[limN+1];

void precarga() {
    ans[0] = 1;
    for(int i=1; i<=limC; i++) {
        int w = i*i*i;
        for(int j=w; j<=limN; j++) {
            ans[j] += ans[j-w];
        }
    }
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n) {
        printf("%lld\n", ans[n]);
    }
}
