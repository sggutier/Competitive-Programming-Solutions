#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4;

double logs[limN];

void precarga(int N = limN) {
    for(int i=1; i<N; i++)
        logs[i] = logs[i-1] + log10f(i);
}

int C(int n, int k) {
    if(n<limN) {
        return (int)(logs[n]-logs[k]-logs[n-k]) + 1;
    }
    double ans = 0.0;
    int div = 1;
    while(n>k) {
        ans += log10f(n--);
        ans -= log10f(div++);
    }
    return ((int) (ans )) + 1;
}

int main() {
    precarga();
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        printf("%d\n", C(a,b));
}
