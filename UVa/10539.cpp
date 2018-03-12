#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int limN = 1e6 ;
const int limP = 80000;
const ll limK = 1e12 ;

int primCnt = 0;
vector<ll> primos[limP];
bool comp[limN + 1];

void criba(int N = limN) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = 1;
    for(int i=2; i<N; i++) {
        if(comp[i])
            continue;
        ll k = i;
        do {
            k *= i;
            primos[primCnt].push_back(k);
        } while(k<=limK) ;
        primCnt ++;
    }
}

map <ll, int> conto;

int calca(ll n) {
    if(n==0)
        return 0;
    auto f = conto.find(n);
    if(f!=conto.end()) {
        return f->second;
    }
    int ans = 0;
    for(int i=0; i<primCnt; i++) {
        if(primos[i][0] > n)
            break;
        int w = upper_bound(primos[i].begin(), primos[i].end(), n) - primos[i].begin();
        ans += w ;
    }
    return conto[n] = ans;
}

void testCase() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%d\n", calca(b) - calca(a-1));
}

int main() {
    criba();

    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
