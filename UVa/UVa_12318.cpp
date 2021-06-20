#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e7 + 5 ;

int T = 0 ;
int laP[LIM_N];

void testCase(ll mod, int M) {
    T ++ ;
    int ans = 0 ;
    int P ;
    scanf("%d", &P);
    vector <int> pol(P+1);
    for(int i=0; i <= P; i++)
        scanf("%d", &pol[i]);
    for(ll x=0; x <= M; x++) {
        ll s = 0, pwr = 1 ;
        for(int i=0; i <= P; i++) {
            s = (s + pol[i] * pwr) % mod ;
            pwr = (pwr * x) % mod ;
        }
        if(laP[s] != T) {
            ans ++ ;
            laP[s] = T ;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int a, b ;
    while(scanf("%d%d", &a, &b) != EOF && (a || b)) {
        testCase(a + 1, b);
    }
}
