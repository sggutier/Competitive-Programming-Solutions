#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    map <int, long long> cnt;
    int minF = (1<<30), maxF = 0;
    long long ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        minF = min(minF, a);
        maxF = max(maxF, a);
        cnt[a]++;
    }

    maxF -= minF;
    if(maxF) {
        for(auto &p : cnt) {
            if(cnt.count(p.first + maxF) )
                ans += p.second * cnt[p.first + maxF];
        }
    }
    else {
        for(auto &p : cnt) {
            ans += (p.second * (p.second-1)) / 2;
        }
    }

    printf("%d %lld\n", maxF, ans);
}
