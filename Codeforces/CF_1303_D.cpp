#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnts[64];

int getNum(ll n) {
        if(n == 0)
                return -1;
        for(int i=0; ; i++) {
                if((1LL<<i) & n) {
                        return i;
                }
        }
        return -1;
}

void testCase() {
        ll n;
        int m ;
        scanf("%lld%d", &n, &m);
        memset(cnts, 0, sizeof(cnts));
        for(int i=0; i<m; i++) {
                int a ;
                scanf("%d", &a);
                cnts[getNum(a)] ++;
        }

        ll ans = 0;
        for(int i=0; i<62; i++) {
                if(((1LL<<i) & n) == 0) {
                        cnts[i+1] += cnts[i]>>1;
                        continue;
                }
                if(cnts[i]) {
                        cnts[i] --;
                }
                else {
                        bool wks = false;
                        for(int j=i+1; j<62; j++) {
                                if(cnts[j]) {
                                        wks = true;
                                        for(int k=j; k>i; k--) {
                                                cnts[k] --;
                                                cnts[k-1] += 2;
                                                ans ++;
                                        }
                                        break;
                                }
                        }
                        if(!wks) {
                                printf("-1\n");
                                return;
                        }
                        cnts[i] --;
                }
                cnts[i+1] += cnts[i]>>1;
        }

        printf("%d\n", ans);
}

int main() {
        int tc;
        for(scanf("%d", &tc); tc; tc--)
                testCase();
}
