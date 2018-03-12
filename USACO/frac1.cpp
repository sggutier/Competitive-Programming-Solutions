/*
ID: me60
LANG: C++11
TASK: frac1
*/
#include <bits/stdc++.h>
using namespace std;

struct frac {
    int num, den;
    frac() {
    }
    frac(int a, int b) {
        num = a;
        den = b;
    }
    friend bool operator<(const frac &A, const frac &B) {
        return A.num*B.den < B.num*A.den;
    }
};

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    
    int n;
    
    scanf("%d", &n);

    frac queb[n*n];
    int qNum = 0;
    for(int i=0; i<=n; i++) {
        for(int j=max(1, i); j<=n; j++) {
            if(__gcd(i, j)==1)
                queb[qNum++] = frac(i, j);
        }
    }

    sort(queb, queb+qNum);

    for(int i=0; i<qNum; i++) {
        printf("%d/%d\n", queb[i].num, queb[i].den);
    }
    
    return 0;
}
