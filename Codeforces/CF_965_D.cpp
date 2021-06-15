#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int cnt[limN];
int maxF[limN];

int main() {
    int L ;
    int ans = 0 ;
    
    scanf("%d%d", &N, &L);
    for(int i=1; i < N; i++)
        scanf("%d", &maxF[i]);

    cnt[0] = 2e9;
    for(int l=0, r=1, x; r < N; r++) {
        for(; r-l > L; l++);
        for(; l < r && cnt[r] < maxF[r]; ) {
            x = min(maxF[r] - cnt[r], cnt[l]);
            cnt[r] += x;
            cnt[l] -= x;
            if(!cnt[l])
                l++;
        }
    }

    for(int i=N-L; i < N; i++)
        ans += cnt[i];

    printf("%d\n", ans);
}
