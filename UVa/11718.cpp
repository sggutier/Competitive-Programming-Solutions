#include <bits/stdc++.h>
using namespace std;

int mod ;

inline int prod(const int &A, const int &B) {
    return (A*B)%mod;
}

inline int sumo(const int &A, const int &B) {
    return (A+B)%mod;
}

int expo(const int &n, int k) {
    if(k==0)
        return 1;
    int p = expo(n, k/2);
    if(k%2)
        return prod(prod(p, p), n);
    return prod(p, p);
}

int testCase() {
    int n, k;
    int sum = 0;
    scanf("%d%d%d", &n, &k, &mod);
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp %= mod;
        sum = sumo(sum, tmp);
    }
    // cout << sum << endl;
    return prod(sum, prod(expo(n%mod, k-1), k%mod));
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %d\n", i, testCase());
    }
}
