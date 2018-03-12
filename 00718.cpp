#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 105;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

bool junto(ll N, ll p, ll q, ll r, ll s) {
    ll d = s-r;
    if(d < 0) {
        d *= -1;
        swap(r, s);
        swap(p, q);
    }
    ll x, y, g;
    g = euclid(p, q, x, y);
    if(d%g)
        return false;
    // printf("%lld %lld | %lld %lld => ", p, r, q, s);
    d /= g;
    q /= g;
    p /= g;
    x *= d;
    y *= d;
    if(x < 0 || 0 < y) {
        // x += q/g;
        // y -= p/g;
        ll w = max(-x/q + (x%q? 1 : 0),
                   y/p + (y%p? 1 : 0));
        x += w*q;
        y -= w*p;
    }
    // printf("[%lld] %lld %lld %lld\n", d, x, -y, g);
    // printf("Se encuentran en el piso %lld\n", p*g*x + r);
    return p*g*x + r < N;
}

bool pasaPor(ll p, ll a, ll b) {
    return p >= b && (p-b)%a==0;
}

void testCase() {
    int N, E;
    int a[limN], b[limN];
    int pini, pfin;
    queue <int> Q;

    scanf("%d%d%d%d", &N, &E, &pini, &pfin);
    for(int i=0; i<E; i++)
        scanf("%d%d", &a[i], &b[i]);
    // printf("bacara\n");
    
    vector <bool> usd(N);
    for(int i=0; i<E; i++) {
        if(!pasaPor(pini, a[i], b[i]))
            continue;
        usd[i] = true;
        Q.push(i);
    }

    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        if(pasaPor(pfin, a[pos], b[pos])) {
            printf("It is possible to move the furniture.\n");
            return ;
        }
        for(int i=0; i<E; i++) {
            if(usd[i] || !junto(N, a[i], a[pos], b[i], b[pos]) )
                continue;
            usd[i] = true;
            Q.push(i);
        }
    }

    printf("The furniture cannot be moved.\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
