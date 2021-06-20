#include <bits/stdc++.h>
using namespace std;

void testCase(int N, int M) {
    set <int> A;
    int tmp;
    int ans = 0;
    while(N--) {
        scanf("%d", &tmp);
        A.insert(tmp);
    }
    while(M--) {
        scanf("%d", &tmp);
        ans += A.count(tmp);
    }
    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
