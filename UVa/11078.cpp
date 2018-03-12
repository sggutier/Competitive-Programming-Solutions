#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N;
    int maxAnt, ans=-(1<<30);
    scanf("%d", &N);
    scanf("%d", &maxAnt);
    for(int i=1; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        ans = max(ans, maxAnt - tmp);
        maxAnt = max(maxAnt, tmp);
    }
    printf("%d\n", ans);
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
    
    return 0;
}
