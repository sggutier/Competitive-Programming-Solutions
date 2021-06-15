#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct BIT {
    int arr[limN];
    int n = limN;
    void mete(int pos, int crg=1) {
        for(; pos<n; pos += (pos & -pos))
            arr[pos] += crg;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos>0; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

BIT bt;
vector <int> crgs[limN];

int main() {
    int N ;
    int nums[limN];
    long long ans = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        nums[i] = min(nums[i], limN-2);
        crgs[nums[i]].push_back(i);
        bt.mete(i);
    }

    for(int i=1; i<=N; i++) {
        if(nums[i] > i)
            ans += bt.saca(nums[i]) - bt.saca(i);
        // printf("%d => %d\n", i, bt.saca(nums[i]));
        for(const int c : crgs[i])
            bt.mete(c, -1);
    }

    printf("%lld\n", ans);
}
