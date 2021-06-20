#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 3e5 + 5;

void hazTab(string &s, int *prev) {
    int n = s.size();
    int i=-1, j=0;
    prev[0] = -1;
    while(j < n) {
        while(i!=-1 && s[i] != s[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

ll cuentaAprs(string &org, int *prev, string tgt) {
    ll ans = 0;
    int n = org.size(), m = tgt.size();
    int i=0, j=0;
    while(j < m) {
        while(i!=-1 && org[i] != tgt[j])
            i = prev[i];
        i++, j++;
        if(i==n) {
            ans ++;
            i = prev[i];
        }
    }
    return ans;
}

ll testCase(int n, string S) {
    if(n == 0)
        return S=="0"? 1 : 0;
    if(n == 1)
        return S=="1"? 1 : 0;
    string a="0", b="1", c;
    int prev[limN];
    int L = S.size();
    hazTab(S, prev);
    for(int i=2; i<=n; i++) {
        c = b+a;
        if(i==n) {
            return cuentaAprs(S, prev, c);
        }
        if(a.size() <= S.size()) {
            a = b;
            b = c;
            continue;
        }
        // printf("%d %d => %d\n", (int) a.size(), (int) b.size(), (int) S.size());
        ll x = cuentaAprs(S, prev, a), y = cuentaAprs(S, prev, b), z;
        ll fusCur = cuentaAprs(S, prev, b.substr(b.size() - (L-1), L-1) + a.substr(0, L-1));
        ll fusNxt = cuentaAprs(S, prev, a.substr(a.size() - (L-1), L-1) + b.substr(0, L-1));
        for(; i<=n; i++, swap(fusCur, fusNxt)) {
            z = x + y + fusCur;
            // printf("\t i = %d, x = %lld, y = %lld, z = %lld\n", i, x, y, z);
            x = y;
            y = z;

            // c = b+a;
            // printf("\t\tComparacion con c: %lld\n", cuentaAprs(S, prev, c));
            // a = b;
            // b = c;
        }
        return y;
    }
    return 1;
}

int main() {
    char tmp[limN];
    int n ;
    int tc = 0;
    while(scanf("%d%s", &n, tmp) != EOF) {
        printf("Case %d: %lld\n", ++tc, testCase(n, tmp));
        // break;
    }
}
