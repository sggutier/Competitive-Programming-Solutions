#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const char* WA = "Game cheated!";
const char* NE = "Data not sufficient!";

inline pii getRan(const int d, const ll l, const ll r) {
    return {l << d, ((r + 1) << d) - 1};
}

int main() {
    int H, Q ;
    ll L, R ;
    vector <pii> negs, post;
    scanf("%d%d", &H, &Q);
    L = 1LL << (H-1);
    R = (2LL << (H-1)) - 1;
    for(int i=0, a, t; i < Q; i++) {
        ll l, r;
        scanf("%d%lld%lld%d", &a, &l, &r, &t);
        auto x = getRan(H - a, l, r);
        if(t) {
            L = max(L, x.first);
            R = min(R, x.second);
        }
        else {
            negs.push_back(x);
        }
    }
    if(R < L) {
        printf("%s\n", WA);
        return 0 ;
    }
    sort(negs.begin(), negs.end());
    for(auto &n : negs) {
        if(n.second < L || R < n.first) continue;
        if(L < n.first && n.second < R) {
            post.emplace_back(L, n.first - 1);
            L = n.second + 1;
        }
        else if(n.second < R) {
            L = n.second + 1;
        }
        else {
            R = n.first - 1;
        }
    }
    // printf("=> %d %d\n", L, R);
    if(R < L && !post.empty()) {
        L = post.back().first;
        R = post.back().second;
        post.pop_back();
    }
    if(R < L) {
        printf("%s\n", WA);
        return 0 ;
    }
    // printf("=> %d %d\n", L, R);
    if(L < R || !post.empty()) {
        printf("%s\n", NE);
        return 0 ;
    }
    printf("%lld\n", L);
}
