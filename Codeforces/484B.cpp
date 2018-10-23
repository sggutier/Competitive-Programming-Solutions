#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 1e6 + 5;

int N ;
bool usd[limN];
priority_queue <pii> lapr;

int main() {
    int ans = 0;

    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        usd[a] = true;
    }

    for(int i=2, w; i<limN; i++) {
        if(!usd[i]) continue;
        if(!lapr.empty()) {
            while(-lapr.top().f + lapr.top().s <= i) {
                w = lapr.top().s;
                lapr.pop();
                lapr.push({-i + i%w, w});
            }
            ans = max(ans, i + lapr.top().f);
        }
        lapr.push({-i, i});
    }

    printf("%d\n", ans);
}
