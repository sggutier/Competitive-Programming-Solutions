#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b ;
    int ans = 2e9 + 7;

    scanf("%d%d%d%d", &n, &m, &a, &b);

    ans = (n/m + (n%m? 1 : 0)) * b;
    for(int w=0; w<=n; w+=m) {
        ans = min(ans, (w/m)*b + (n-w)*a);
    }

    printf("%d\n", ans);
}
