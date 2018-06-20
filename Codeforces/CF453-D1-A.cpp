#include <bits/stdc++.h>
using namespace std;

int main() {
    double acum = 0.0, ans = 0.0, pb;
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i=m; i>=0; i--) {
        pb = 1 - acum - pow((i-1.0)/m, n);
        ans += pb*i;
        acum += pb;
    }
    printf("%.9lf\n", ans);
}
