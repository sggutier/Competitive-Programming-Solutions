#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limM = 15;

inline ll lcm(ll a, ll b) {
    return (a/__gcd(abs(a),abs(b)))*b;
}


ll n, M ;
ll nums[limM];
ll ans = 0;

void bruta(int pos, ll prod) {
    if(prod>n)
        return;
    if(pos==M) {
        ans += n/prod;
        return;
    }
    bruta(pos+1, prod);
    bruta(pos+1, -lcm(prod, nums[pos]));
}

void testCase() {
    for(int i=0; i<M; i++)
        scanf("%lld", &nums[i]);
    ans = n;
    bruta(0, -1);
    printf("%lld\n", n-ans);
}

int main() {
    while(scanf("%lld%lld", &n, &M)!=EOF)
        testCase();
}
