#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 ;

int rem = limN;
vector <ll> divs;
vector <int> sgs[limN];

void calcDivs(ll x) {
    for(ll i=1; i*i<=x; i++) {
        if(x%i) continue;
        divs.push_back(i);
        if(i*i != x)
            divs.push_back(x/i);
    }
    sort(divs.begin(), divs.end());
}

void calcSgs(int pos) {
    // printf("calcando %lld\n", divs[pos]);
    for(int i=0; i<=pos; i++)
        if(divs[pos] % divs[i] == 0)
            sgs[pos].push_back(i);
}

void reca(int pos, int k) {
    if(k==0) {
        printf("%lld ", divs[pos]);
        if( !(--rem) ) {
            printf("\n");
            exit(0);
        }
        return;
    }
    if(pos==0) {
        printf("1 ");
        if( !(--rem) ) {
            printf("\n");
            exit(0);
        }
        return;
    }
    if(sgs[pos].empty())
        calcSgs(pos);
    if((int) sgs[pos].size() == 2) {
        for(int i=0; i<k; i++) {
            printf("1 ");
            if( !(--rem) ) {
                printf("\n");
                exit(0);
            }
        }
        printf("%lld ", divs[pos]);
        if( !(--rem) ) {
            printf("\n");
            exit(0);
        }
        return;
    }
    for(const int a : sgs[pos])
        reca(a, k-1);
}

int main() {
    ll x, k;
    scanf("%lld%lld", &x, &k);
    if(x==1) {
        printf("1\n");
        return 0;
    }
    if(k > limN) {
        for(int i=0; i<limN; i++)
            printf("1 ");
        printf("\n");
        return 0;
    }
    calcDivs(x);
    // printf("%d\n", (int) divs.size());
    reca(divs.size()-1, k);
    printf("\n");
}
