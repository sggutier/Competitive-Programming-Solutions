#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e5 + 5;

vector <int> facs[limN];

void criba() {
    for(int i=2; i<limN; i++) {
        if(!facs[i].empty()) continue;
        for(int j=i; j<limN; j+=i)
            facs[j].push_back(i);
    }
}

int N, D ;
int divs[limN];
ll ans[limN];
int nums[limN];

void calcDivs(int n, vector <int> &f, int pos=0) {
    if(pos == (int) f.size()) {
        // printf("%d ", n);
        divs[D++] = n;
        return;
    }
    if(n % f[pos] == 0)
        calcDivs(n / f[pos], f, pos);
    calcDivs(n, f, pos+1);
}

ll expBin(ll n, ll k) {
    if(k==0)
        return 1LL;
    ll mit = expBin(n, k/2);
    return ( ((mit * mit) % mod) * (k%2? n : 1) ) % mod;
}

ll proca(int w) {
    D = 0;
    calcDivs(w, facs[w]);
    sort(divs, divs+D);
    divs[D] = 1e9;
    ll res = 1, nv;
    // printf("%d\n", w);
    for(int i=0, u=-1, k; i<D; i++) {
        k = lower_bound(nums+u+1, nums+N, divs[i+1]) - nums;
        // u = lower_bound(nums, nums+N, divs[i]) - nums;
        k--;
        // u--;
        if(i==D-1)
            k = N-1;
        if(i != D-1)
            nv = expBin(i+1, k-u);
        else
            nv = (expBin(i+1, k-u) - expBin(i, k-u) +mod)%mod;
        res = (res * nv)% mod;
        // printf("\t%d => %d %d || %lld\n", divs[i], u, k, expBin(i+1, k-u));
        u = k;
        // if(i+1 != D) {
        //     ng = (ng + ans[divs[i]]) % mod;
        //     printf("\t\t quitando %d %lld\n", divs[i], ans[divs[i]]);
        // }
    }
    // printf("res es %lld\n", res);
    // printf("tot es %lld\n", (res - ng  + mod) % mod);
    // return ans[w] = (res - ng  + mod) % mod;
    return ans[w] = res;
}

int main() {
    criba();
    scanf("%d", &N);
    int maxK = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        maxK = max(maxK, nums[i]);
    }
    sort(nums, nums+N);

    long long tt = 1;
    ans[1] = 1;
    for(int i=2; i<=maxK; i++)
        tt = (tt + proca(i)) % mod;

    printf("%lld\n", tt);
}
