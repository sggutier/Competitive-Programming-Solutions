#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll *x=NULL, ll *y=NULL) {
    if(b==0) {
        if(x) {
            *x = 1, *y = 0;
        }
        return a;
    }
    ll x2, y2;
    ll c = a/b, d = gcd(b, a-b*c, x? &x2 : NULL, x? &y2 : NULL);
    if(x) {
        *x = y2;
        *y = x2 - c*y2;
    }
    return d;
}

void testCase(ll n, ll k) {
    if(n%k==0) {
        printf("0 %lld\n", k);
        return;
    }
    printf("%lld %lld\n", -n, n);
    //ll a = n/k, b=a+1;
    //ll x, y;
    //gcd(a, b, &x, &y);
    //printf("%lld %lld\n", x*n, y*n);
}

int main() {
    int tc;
    int a, b;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &a, &b);
        testCase(a, b);
    }
}
