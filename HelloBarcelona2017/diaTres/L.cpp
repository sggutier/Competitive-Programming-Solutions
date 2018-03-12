#include <bits/stdc++.h>
using namespace std;
const int limN = 65;

struct frac {
    long long num, den;
    frac() {
    }
    frac(long long a, long long b ) {
        long long c = __gcd(a, b);
        num = a/c;
        den = b/c;        
    }
};

frac operator-(const frac &A, const frac &B) {
    return frac(A.num*B.den - B.num*A.den, A.den*B.den);
}

frac operator+(const frac &A, const frac &B) {
    return frac(A.num*B.den + B.num*A.den, A.den*B.den);
}

frac operator*(const frac &A, const frac &B) {
    return frac(A.num*B.num, A.den*B.den);
}

bool usd[limN][limN];
frac dpMemo[limN][limN];

frac jogo(int n, int m) {
    if(usd[n][m])
        return dpMemo[n][m];
    usd[n][m] = true;
    if(m==0) {
        return dpMemo[n][m] = frac(0, 1);
    }
    return dpMemo[n][m] = frac(m,n+m)*(frac(1,1) - jogo(n, m-1));
}

int main() {
    int tc;
    int a, b;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d%d", &a, &b);
        frac ans = frac(1,1) - jogo(a, b);
        printf("%lld/%lld\n", ans.num, ans.den);
    }
}
