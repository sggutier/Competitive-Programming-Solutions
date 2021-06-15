#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

int main() {
    ll n, k ;
    cin >> n >> k ;
    n = min(n, k-1);
    if(k >= 2*n) {
        printf("0\n");
        return 0 ;
    }
    ll r = k - n ;
    printf("%lld\n", (n+1-r) / 2);
}
