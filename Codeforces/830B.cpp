#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

struct BIT {
    int arr[limN];
    int n ;
    BIT(int n) : n(n) {}
    void mete(int pos, int nov) {
        for(pos++; pos<=n; pos+=(pos & -pos))
            arr[pos] += nov;
    }
    int saca(int pos) {
        int ans = 0;
        for(pos++; pos>0; pos-=(pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

int main() {
    int N, T=0;
    int ord[limN];
    int nums[limN];
    vector <int> poss[limN];
    long long ans = 0;
    scanf("%d", &N);
    BIT bt(N);
    for(int i=0; i<N; i++) {
        ord[i] = i;
        scanf("%d", &nums[i]);
        bt.mete(i, 1);
    }
    sort(ord, ord+N,
         [&nums] (int a, int b) {
             return (nums[a] != nums[b])? nums[a] < nums[b] : a<b;
         });
    for(int i=0; i<N; i++) {
        if(!i || nums[ord[i]] != nums[ord[i-1]])
            T++;
        poss[T-1].push_back(ord[i]);
    }
    for(int t=0, up=0, urlp, rem=N; t<T; t++) {
        // printf("%d => ", t);
        // for(const int &c:poss[t])
        //     printf("[%d %d] ", c, nums[c]);
        // printf("\n");
        int K = poss[t].size();
        int w = (lower_bound(poss[t].begin(), poss[t].end(), urlp) - poss[t].begin()) % K;
        for(int j=0; j<K; j++) {
            int rl = poss[t][(j+w)%K];
            int p = bt.saca(rl)-1;
            ans += (p-up+rem)%rem + 1;
            // printf("(%d) %d %d [%d] => %d %d\n", nums[rl], up, p, rl, rem, (p-up+rem)%rem + 1);
            // for(int i=0; i<N; i++)
            //     printf("%d ", bt.saca(i)-1);
            // printf("\n");
            bt.mete(rl, -1);
            up = p;
            urlp = rl;
            rem --;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
