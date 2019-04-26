#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e6 + 5;

int phi[limN];
ll acms[limN];

void calcF() {
    for(int i=2; i<limN; i++)
        phi[i] = i;
    for(int i=2; i<limN; i++) {
        if(phi[i] != i)
            continue ;
        for(int j=i; j<limN; j+=i) {
            phi[j] -= phi[j] / i;
        }
    }

    for(int i=2; i<limN; i++) {
        ll w = ((ll) i) * phi[i];
        for(int j=i; j<limN; j+=i)
            acms[j] += w;
    }
}

int main() {
    calcF();

    int n ;

    scanf("%d", &n);
    for(int i=0, a; i<n; i++) {
        scanf("%d", &a);
        printf("%lld\n", a * (acms[a]/2 +1) );
    }
}
