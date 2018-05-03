#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define abs(x) ( x > 0? x : -x )
const int limP = 34;
typedef long long ll;

ll pots[limP];
bool ans[limP];
ll sumaSgns[limP][2];

int sgno(ll n) {
    return n/abs(n)>0? 1 : 0;
}

void llena(ll n) {
    if(n==0) return;
    for(int i=0; i<limP; i++) {
        if(pots[i]==n) {
            ans[i] = true;
            return;
        }
        if(abs(sumaSgns[i][sgno(pots[i])]) >= abs(n) && sgno(pots[i])==sgno(n)) {
            ans[i] = true;
            llena(n-pots[i]);
            break;
        }
    }
}

int main() {
    pots[0] = 1;
    sumaSgns[0][sgno(1)] = 1;
    for(int i=1; i<limP; i++) {
        pots[i] = -pots[i-1]*2;
        sumaSgns[i][0] = sumaSgns[i-1][0];
        sumaSgns[i][1] = sumaSgns[i-1][1];
        sumaSgns[i][sgno(pots[i])] += pots[i];
    }
    ll n ;
    cin >> n ;
    for(; true; n++) {
        memset(ans, 0, sizeof(ans));
        // printf("%lld = \n", n);
        llena(n);
        int maxP = 0;
        for(int i=limP-1; i>=0; i--) {
            if(!ans[i])  continue;
            maxP = i;
            break;
        }
        for(int i=maxP; i>=0; i--)
            printf("%c", ans[i]? '1' : '0');
        printf("\n");
        break;
    }
}
