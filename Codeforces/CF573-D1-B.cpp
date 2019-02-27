#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool usd[limN];

int main() {
    int ans = 0;

    int N ;
    priority_queue < pair<int, int> > Q ;

    scanf("%d", &N);
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        Q.push({-a, i});
    }

    Q.push({-1, 1});
    Q.push({-1, N});
    N ++;
    while(!Q.empty()) {
        int pos = Q.top().second, d = -Q.top().first;
        Q.pop();
        if(usd[pos]) continue;
        usd[pos] = true;
        ans = max(ans, d);
        d ++;
        for(int s = pos-1; s <= pos+1; s += 2)
            if(s % N)
                Q.push({-d, s});
    }

    printf("%d\n", ans);
}
