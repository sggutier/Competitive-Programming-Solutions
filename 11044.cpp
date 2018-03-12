#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    int a, b;
    for(scanf("%d",&tc); tc; tc--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", (int)(ceil((a-2)/3.0) * ceil((b-2)/3.0)));
    }

    return 0;
}
