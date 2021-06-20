#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 4e6 + 1;
int phi[LIM];
long long ans[LIM];

void calculatePhi() {
    rep(i,0,LIM) phi[i] = i&1 ? i : i/2;
    for(int i = 3; i < LIM; i += 2)
        if(phi[i] == i)
            for(int j = i; j < LIM; j += i)
                (phi[j] /= i) *= i-1;
}

void calcDivs() {
    for(int i=2; i < LIM; i++) {
        long long w = phi[i];
        for(int j=i, k=1; j < LIM; j += i, k++) {
            ans[j] += k * w;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    calculatePhi();
    calcDivs();

    for(int i=1; i < LIM; i++) ans[i] += ans[i-1];

    int N ;

    while(scanf("%d", &N) && N) {
        printf("%lld\n", ans[N]);
    }
}
