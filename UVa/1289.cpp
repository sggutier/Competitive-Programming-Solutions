#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 1e4 + 5;

void testCase(int N) {
    vector <vi> ps;
    vector <int> tams(LIM_N);
    map <pii, int> parCnt;
    set <pii> cncs, dolo;
    int ans = 0 ;

    ps.resize(N);
    for(int i=0; i < N; i++) {
        int k ;
        scanf("%d", &k);
        ps[i].resize(k);
        for(int j=0; j < k; j++) {
            scanf("%d", &ps[i][j]);
            tams[ps[i][j]]++;
            if(j)
                parCnt[{ps[i][j-1],ps[i][j]}] ++;
        }
    }

    int pv = -1;
    for(int p=0; p < LIM_N; p++) {
        if(!tams[p]) continue ;
        cncs.insert({pv, p});
        pv = p;
    }

    for(const auto &v : ps) {
        int reps = 0 ;
        bool ct = true;
        int prePrev = -2;
        pv = 0 ;
        for(const auto a : v) {
            if(pv != a) {
                auto it = cncs.find({pv, a});
                if((!ct && tams[pv] != reps && parCnt[{prePrev,pv}] == 1)  ||  it == cncs.end()) {
                    ans ++;
                    ct = true;
                }
                else {
                    cncs.erase(it);
                    ct = false;
                }
                reps = 0 ;
            }
            reps ++ ;
            prePrev = pv;
            pv = a ;
        }
    }

    printf("%d\n", (ans - N) + (ans - 1));
}

int main() {
    int N ;
    for(int i=1; scanf("%d", &N) != EOF; i++) {
        printf("Case %d: ", i);
        testCase(N);
    }
}
