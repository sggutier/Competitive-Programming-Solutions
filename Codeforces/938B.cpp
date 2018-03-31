#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5;

int main() {
    const int b = 1e6;
    int N ;
    int ans = 0;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        ans = max(ans, min(a-1, b-a));
    }
    printf("%d\n", ans);
}
