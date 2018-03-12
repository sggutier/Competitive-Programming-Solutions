#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--) {
        int minS, maxS, n;
        maxS = -(minS=(1<<30));
        scanf("%d", &n);
        for(; n; n--) {
            int tmp ;
            scanf("%d", &tmp);
            maxS = max(maxS, tmp);
            minS = min(minS, tmp);
        }
        printf("%d\n", 2*(maxS-minS));
    }
    
    return 0;
}
