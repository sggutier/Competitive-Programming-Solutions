#include <bits/stdc++.h>
using namespace std;
const int limN = 2e6 + 5;

bool comp[limN];
int phi[limN];

void criba(int n=limN) {
    for(int i=2; i*i<n; i++) 
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=0; i<n; i++) {
        phi[i] = 1;
    }
    for(int i=2; i<n; i++) {
        if(comp[i])
            continue;
        for(int j=i; j<n; j+=i) {
            int w = j/i;
            int a=i, b=1;
            while(w%i==0) {
                w /= i;
                b = a;
                a *= i;
            }
            phi[j] *= a-b;
            // cout << i << " " << j<< " => " << a << " " << b << endl;
        }
    }
}

long long phiDepth[limN];

void precarga(int n=limN) {
    criba();
    for(int i=2; i<n; i++) {
        phiDepth[i] = phiDepth[phi[i]] + 1;
        // cout << i << " " << phi[i] << endl;
    }
    // cout << n << endl;
    for(int i=3; i<n; i++) {
        phiDepth[i] += phiDepth[i-1];
    }
}

long long testCase(int a, int b) {
    if(a>=b)
        swap(a,b);
    return phiDepth[b] - phiDepth[a-1];
}

int main() {
    precarga();

    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", testCase(a,b));
    }
    
    return 0;
}
