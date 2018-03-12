#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 5;

struct BIT {
    int arr[MAX_N];
    void reset() {
        memset(arr, 0, sizeof(arr));
    }
    void mete(int pos, int nov=1) {
        for(; pos<MAX_N; pos += (pos & -pos))
            arr[pos] += nov;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos -= (pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

BIT bt;
int N;
int nums[MAX_N];
int perm[MAX_N];

void testCase() {
    bt.reset();
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        perm[i] = i;
    }

    sort(perm, perm+N, [] (const int &a, const int &b) -> bool {return nums[a] < nums[b];});
    for(int i=0; i<N; i++)
        nums[perm[i]] = i+1;

    long long ans = 0LL;
    for(int i=N-1; i>=0; i--) {
        ans += bt.saca(nums[i]-1);
        bt.mete(nums[i]);
    }

    printf("%lld\n", ans);
}

int main() {
    while(scanf("%d", &N)!=EOF)
        testCase();
}
