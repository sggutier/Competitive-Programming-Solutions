#include <bits/stdc++.h>
using namespace std;
const int limN = 50000 + 5;
const int limQ = 230;
typedef unsigned int ll;

int N, K ;
int nums[limN];
ll preCos[limQ][limN];

ll miniRan(int a, int b, int x, int y) {
    // printf("miniran %d %d %d %d\n", a, b, x, y);
    static int W = 0;
    static vector<int> usdId(limN, -1);
    static vector<ll> reps(limN);
    W ++ ;

    ll ans = 0;
    for(int i=a, p; i<=b; i++) {
        p = nums[i];
        if(usdId[p] != W) {
            usdId[p] = W;
            reps[p] = 0;
        }
        reps[p]++;
    }
    for(int i=x, p; i<=y; i++) {
        p = nums[i];
        if(usdId[p] == W)
            ans += reps[p];
    }

    return ans;
}

ll buenRan(int a, int b) {
    // printf("bran %d %d\n", a, b);
    if(a % K) swap(a, b);
    return preCos[a/K][b];
}

ll ran(int a, int b) {
    // printf("consiguiendo %d %d\n", a,b);
    if(a <= 0 || b <= 0)
        return 0;

    // vector <ll> cnt(limN);
    // ll ans = 0;
    // for(int i=1; i<=a; i++)
    //     cnt[nums[i]] ++;
    // for(int i=1; i<=b; i++)
    //     ans += cnt[nums[i]];

    
    if(b % K == 0) swap(a, b);
    if(a % K == 0)
        return preCos[a/K][b];
    int r1 = a%K, r2 = b%K ;
    a -= r1, b -= r2;
    // printf(">> %d %d %d %d\n", a, r1, b, r2);
    int p = buenRan(a + r1, b);
    int q = buenRan(a, b + r2);
    int r = buenRan(a, b);
    int s = miniRan(a + 1, a + r1, b+1, b + r2);
    int res = p +  q - r + s;
    // printf("\t %d %d %d %d | %d | %d\n", p, q, r, s, res, ans);
    return res;
}

ll granRan(int a, int b, int x, int y) {
    return ran(b, y) - ran(b, x-1) - ran(a-1, y) + ran(a-1, x-1);
}

void preProca() {
    vector <ll> cnt(limN);
    K = max(1, (int) sqrt(N));
    // printf("k es %d\n", K);
    for(int i=1; i*K <= N; i++) {
        for(int a=0, p; a<K; a++) {
            p = nums[i*K - a];
            cnt[p] ++;
            // printf("mando %d %d\n", p, i* K - a);
        }
        ll tt = 0;
        for(int j=1, p; j<=N; j++) {
            p = nums[j];
            tt += cnt[p];
            // printf("%u ", tt);
            preCos[i][j] = tt;
        }
        // printf("\n");
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &nums[i]);
    preProca();
    int Q ;
    scanf("%d", &Q);
    for(int i=0, a, b, x, y; i<Q; i++) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        printf("%u\n", granRan(a, b, x, y));
    }
}
