#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumo(ll n) {
    return (n*(n+1))/2;
}

ll solvo(ll c) {
    ll r = sqrt(8*c+1);
    return (r-1)/2;
}

void testCase(int s, ll d) {
    d += sumo(s-1)-1;
    printf("%lld\n", solvo(d) + 1);
}

int main() {
    int a;
    ll b ;
    while(scanf("%d%lld", &a, &b)!=EOF) {
        testCase(a,b);
    }
}
