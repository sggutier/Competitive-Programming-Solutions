#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    priority_queue <ll> Q;
    int N ;
    ll ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        Q.push(-a);
    }

    while(Q.size() > 1) {
        if(((int) Q.size())%2 == 0)
            Q.push(0);
        ll a = Q.top(); Q.pop();
        ll b = Q.top(); Q.pop();
        ll c = Q.top(); Q.pop();
        Q.push(a+b+c);
        ans += -a-b-c;
    }

    printf("%lld\n", ans);
}
