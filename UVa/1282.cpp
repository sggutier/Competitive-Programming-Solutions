// - LiveArchive was not working when I was doing this problem, so I solved in UVa.
// - The amount of times some string appears in another one can be calculated with KMP if
//   both strings are small enough.
// - If n is small enough (F(n) having a length of just a little more than p), F(n) can be
//   calculated and then the pattern searched.
// - Otherwise, for some k <= n-2, |F(k)| > |p| and therefore |F(k+1)| > p.
// - The amount of times p appears in F(k+2) is the number of times it appears in F(k) plus
//   the number of times it appears in F(k+1) plus the number of times it appears in the
//   intersection.  The intersection is the part that is the ending of F(k) that has length
//   less than p joined with the beginning of F(k+1) with length less than the one of p.
// - From this point on, all the first |p|-1 characters of all F's are all the same.
// - Also, all the last |p|-1 characters of the F's are either equal to the ones of F(k) or
//   to the ones of F(k+1).
// - Because of the last two points, all the intersections are the result of joining the first
//   characters of F(k) with the last parts of F(k) and F(k+1).  They appear first one, then
//   second one, then the first one and so on.
// - Since all the intersections are the same, the amount of times p appears in j is the
//   amount of times it appears in j-1 plus the amount of times it appears in j-2 plus the
//   times it appears in the corresponding intersection.
// - Getting the F's takes less than n*|p| operations and KMP has to be done at most 3 times,
//   giving taking at most about 6*|p| operations.  This should be enough to pass the test data.
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
