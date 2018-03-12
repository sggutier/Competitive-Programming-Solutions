#include <bits/stdc++.h>
using namespace std;

inline int testCase(int n) {
    return n==1? 1 : ((((n ^ (1<<(31 - __builtin_clz(n))))<<1) | 1) + n-1)%n;
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n!=0)
        printf("%d\n", testCase(n));
    
    return 0;
}
