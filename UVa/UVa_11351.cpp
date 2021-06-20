#include <bits/stdc++.h>
using namespace std;

int jos(int n, int k) {
    if(n==1)
        return 0;
    return (jos(n-1, k) + k)%n;
}

int main() {
    int tc, a, b;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", i, jos(a, b)+1);
    }
}
