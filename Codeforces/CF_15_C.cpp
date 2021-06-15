#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calcXor(ll n) {
    int rem = n%4;
    if(rem==0)
        return n;
    else if(rem==1)
        return 1;
    else if(rem==2)
        return n+1;
    else
        return 0;
}

int main() {
    ll ans = 0;
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        ll x, m;
        scanf("%lld%lld", &x, &m);
        ans ^= calcXor(x-1) ^ calcXor(x+m-1);
    }
    printf("%s\n", ans==0? "bolik" : "tolik");
}
