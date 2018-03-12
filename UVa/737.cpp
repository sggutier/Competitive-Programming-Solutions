#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int inf = (1<<30);

par iSec(par A, par B) {
    return make_pair(max(A.first, B.first), min(A.second, B.second));
}

void testCase(int N) {
    par ans[] = {par(-inf, inf), par(-inf, inf), par(-inf, inf)};
    par tmp[] = {par(-inf, inf), par(-inf, inf), par(-inf, inf)};
    while(N--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        tmp[0] = par(a, a+d);
        tmp[1] = par(b, b+d);
        tmp[2] = par(c, c+d);
        for(int i=0; i<3; i++)
            ans[i] = iSec(ans[i], tmp[i]);
    }
    printf("%d\n", max(0, (ans[0].s-ans[0].f)*(ans[1].s-ans[1].f)*(ans[2].s-ans[2].f)));
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
