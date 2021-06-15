#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii;

map <ll, pii> nxt ;

pii memo(const ll n) {
    if(n == 0LL) {
        return {-10, 0};
    }
    auto it = nxt.find(n);
    if(it != nxt.end()) {
        return it->second;
    }
    pii &ans = nxt[n];
    for(int x=0; x <= 6; x++) {
        for(int y=0; x + y <= 6 && x*4 + y * 7 <= n; y++) {
            if((x*4 + y*7) % 10 == n % 10 &&
               memo((n - x * 4 - y * 7) / 10) != make_pair(-1, -1)) {
                // printf("%lld => %d %d\n", n, x, y);
                return ans = {x, y};
            }
        }
    }
    return ans = {-1, -1} ;
}

void testCase(ll n) {
    // ll k = n ;
    nxt.clear();
    if(memo(n) == make_pair(-1, -1)) {
        printf("-1\n");
        return;
    }
    ll ans[] = {0, 0, 0, 0, 0, 0};
    ll pot = 1 ;
    auto pr = nxt[n] ;
    // printf("-------\n");
    while(n) {
        int a = pr.first;
        int b = pr.second;
        // printf("%lld => %d %d\n", n, a, b);
        for(int i=0; i < a; i++) {
            ans[i] += pot * 4 ;
        }
        for(int i=0; i < b; i++) {
            ans[i + a] += pot * 7 ;
        }
        n = (n - a * 4 - b * 7) / 10;
        // printf("\t%lld\n", n);
        pr = nxt[n];
        pot *= 10 ;
    }
    for(int i=0; i < 6; i++)
        printf("%lld ", ans[i]);
    printf("\n");
    // printf("%lld ===>  %lld\n", k, ans[0] + ans[1] + ans[2] + ans[3] + ans[4] + ans[5]);
}

int main() {
    int tc ;
    ll a ;
    scanf("%d", &tc);
    for(int i=0; i < tc; i++) {
        scanf("%lld", &a);
        testCase(a);
    }
}
