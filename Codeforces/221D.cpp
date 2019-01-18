#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int totCnt[limN];

bool isInter(int n) {
    if(n >= limN) return false;
    return totCnt[n] >= n;
}

int N, Q ;
int nums[limN];
int ans[limN];
int ls[limN], rs[limN];
int cnt[limN];

void queries(int tp) {
    for(int i=1; i<=N; i++)
        cnt[i] = cnt[i-1] + (nums[i]==tp? 1 : 0);
    for(int i=0; i<Q; i++) {
        if(cnt[rs[i]] - cnt[ls[i]-1] == tp)
            ans[i] ++;
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        if(nums[i] < limN)
            totCnt[nums[i]] ++;
    }
    for(int i=0; i<Q; i++) {
        scanf("%d%d", &ls[i], &rs[i]);
    }

    for(int i=1; i<=N; i++)
        if(isInter(i))
            queries(i);

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
}
