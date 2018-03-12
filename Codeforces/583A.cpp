#include <bits/stdc++.h>
using namespace std;
const int limN = 55;

bool usdA[limN], usdB[limN];

int main() {
    int n ;
    scanf("%d", &n);
    for(int i=1; i<=n*n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(usdA[a] || usdB[b])
            continue;
        printf("%d ", i);
        usdA[a] = true;
        usdB[b] = true;
    }
    printf("\n");
}
