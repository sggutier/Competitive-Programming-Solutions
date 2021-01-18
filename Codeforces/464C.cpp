#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll mod = 1e9 + 7 ;
const int LIM_N = 1e5 + 5 ;
const int LIM_B = 10;

pair <ll, ll> calcVs(const string &s, ll *pot10s, ll *acms) {
    ll p10 = 1;
    ll df = 0 ;
    for(int i=s.size() - 1; i >= 0; i--) {
        int d = s[i] - '0';
        df = (df + acms[d] * p10) % mod;
        p10 = (pot10s[d] * p10) % mod ;
    }
    return {p10, df};
}

void procQ(const pair <int, string> Q, ll *pot10s, ll *acms) {
    auto df = calcVs(Q.second, pot10s, acms);
    pot10s[Q.first] = df.first;
    acms[Q.first] = df.second;
}

int main() {
    char tmp[LIM_N];
    string S ;
    int Q ;
    pair <int, string> qs[LIM_N];
    ll pot10s[LIM_B], acms[LIM_B];

    scanf("%s", tmp);
    S = tmp;
    scanf("%d", &Q);
    for(int i=0, a; i < Q; i++) {
        scanf("%d%s", &a, tmp);
        qs[i] = {a, tmp + 2};
    }

    for(int i=0; i < LIM_B; i++) {
        pot10s[i] = 10 ;
        acms[i] = i;
    }

    for(int i=Q-1; i >= 0; i--) {
        procQ(qs[i], pot10s, acms);
    }

    auto ans = calcVs(S, pot10s, acms);

    printf("%lld\n", ans.second);
}
