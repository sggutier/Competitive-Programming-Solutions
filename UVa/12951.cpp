#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3;
const int inf = (1<<30);

struct BIT {
    int arr[limN+5];
    BIT() {
        for(int i=0; i<=limN; i++)
            arr[i] = -inf;
    }
    void mete(int pos, int nov) {
        for(; pos<=limN; pos+=(pos & -pos))
            arr[pos] = max(arr[pos], nov);
    }
    int saca(int pos) {
        int ans = -(1<<30);
        for(; pos>0; pos -= (pos & -pos))
            ans = max(ans, arr[pos]);
        return ans;
    }
};

void testCase(int numCnt, int cost) {
    int ans = 0;
    BIT bit;
    for(int i=0; i<numCnt; i++) {
        int n ;
        scanf("%d", &n);
        bit.mete(n, ans-n);
        ans = max(ans, n-cost + bit.saca(n-cost));
    }
    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
