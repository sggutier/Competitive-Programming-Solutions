#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;

int maxAr(int a, int b) {
    if( a>b)
        swap(a, b);
    a *= 4;
    b *= 4;
    return max(a/2, min(b/4, a));
}

void testCase(int N) {
    pair <int,int> ans(0, 0);
    int a, b;
    for(int i=1; i<=N; i++) {
        scanf("%d%d", &a, &b);
        ans = max(ans, make_pair(maxAr(a, b), -i));
    }
    printf("%d\n", -ans.second);
}

int main() {
    int a;
    while(scanf("%d", &a)!=EOF && a)
        testCase(a);
}
