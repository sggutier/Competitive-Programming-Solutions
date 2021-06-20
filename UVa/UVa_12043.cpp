#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e5 + 2;

int numDivs[LIM_N];
ll divSum[LIM_N];

void init() {
    for(int i=1; i < LIM_N; i++) {
        for(int j=i; j < LIM_N; j+=i) {
            numDivs[j] ++;
            divSum[j] += i;
        }
    }
}

void testCase() {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int p = a - a % k ;
    if(p < a) p += k;
    ll ds = 0 ;
    int dc = 0;
    for(; p <= b; p+=k) {
        dc += numDivs[p];
        ds += divSum[p];
    }
    printf("%d %lld\n", dc, ds);
}

int main() {
    init();
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
}
