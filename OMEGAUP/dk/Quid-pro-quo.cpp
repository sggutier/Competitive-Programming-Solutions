#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int limN = 1e6 + 5;
const int lim4 = limN*5;

int N ;
int vagAct = 1;
ll vals[lim4];

void mete(const int tgt, const ll nov) {
    int pos=0, l=1, r=N, piv;
    while(l < r) {
        vals[pos] += nov;
        piv = (l+r)/2;
        if(tgt <= piv) {
            pos = pos*2 + 1;
            r = piv;
        }
        else {            
            pos = pos*2 + 2;
            l = piv + 1;
        }
    }
    vals[pos] += nov;    
}

int query2(ll k) {
    return 0;
    int pos = 0, l = 1, r = N, piv;
    int ans ;

    while(l < r) {
        piv = (l+r)/2;
        if(k > vals[pos*2 + 1]) {
            k -= vals[pos*2 + 1];
            l = piv+1;
            pos = pos*2 + 2;
        }
        else {
            r = piv;
            pos = pos*2 + 1;
        }
    }
        
    ans = abs(vagAct - l);
    vagAct = l;
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int Q ;
    scanf("%d", &N);
    scanf("%d", &Q);
    // cin >> N >> Q;
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        // cin >> a ;
        // mete(i, a);
    }
    // cout << maxP << endl;
    while(Q--) {
        int t;
        scanf("%d", &t);
        //        cin >> t ;
        if(t==1) {
            // char tmp[100];
            // scanf("%s", tmp);
            // scanf("%s", tmp);
            ll a, b ;
            // scanf("%d%d", &a, &b);
            scanf("%lld", &a);
            scanf("%lld", &b);
            // cin >> a ;
            // cin >> b ;
            // mete(a, b);
        }
        else {
            ll k ;
            scanf("%lld", &k);
            // cin >> k;
            // printf("%d\n", query2(k));
            // cout << query2(k) << '\n';
            // char tmp[100];
            // scanf("%s", tmp);
            printf("%d\n", 0);
        }
    }
}
