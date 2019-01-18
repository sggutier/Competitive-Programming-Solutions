#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;
typedef long long ll;

vector <int> prims;
bool isComp[limN + 15];
int pd[limN + 15];
int fca[limN + 15];

void inita() {
    isComp[0] = isComp[1] = true;
    for(int i=2; i<=limN; i++) {
        if(!isComp[i])
            prims.push_back(i);
        for(int j=2*i; j<=limN; j+=i) {
            isComp[j] = true;
        }
    }
}

int testCase(ll a, ll b) {
    int r = b-a+1;
    memset(pd, 0, sizeof(pd));
    for(const int p : prims) {
        ll w = (p-a%p) % p;
        for(int i=w, k; i<r; i+=p) {
            pd[i] ++;
            if(pd[i] != 1)
                continue;
            w = i+a;
            k = 0;
            while(w % p == 0) {
                w /= p;
                k ++;
            }
            fca[i] = k+1;
            if(w != 1)
                pd[i] ++;
            // printf("%lld = %d ^ %d\n", i+a, p, fca[i]-1);
        }
    }

    int ans = 0;
    for(ll c = max(a, 2LL); c <= b; c++) {
        // printf("%lld | %d %d\n", c, pd[c-a], fca[c-a]);
        if(pd[c-a] == 0 || (pd[c-a] == 1 && !isComp[fca[c-a]]))
            ans ++;
    }
    
    return ans;
}

int main() {
    inita();
    int tc;
    scanf("%d", &tc);
    ll a, b;
    for(int i=0; i<tc; i++) {
        scanf("%lld%lld", &a, &b);
        printf("%d\n", testCase(a, b));
    }
}
