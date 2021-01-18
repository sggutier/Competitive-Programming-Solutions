#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    while(scanf("%d", &n)!=EOF) {
        long double p = log10l(2) * n;
        long double d = ceill(p) - p;
        printf("2^%d = %.3Lfe-%d\n", -n, powl(10, d), int(ceill(p)));
    }
}
