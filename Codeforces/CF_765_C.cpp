#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll k, a, b ;
    scanf("%lld%lld%lld", &k, &a, &b);
    if(a==0 && b==0) {
        printf("0\n");
        return 0;
    }
    if(a<k && b<k) {
        printf("-1\n");
        return 0;
    }
    if(a < b) swap(a, b);
    if(a % k && b < k) {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", a/k + b/k);
}
