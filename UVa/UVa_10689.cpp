#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int mod ;

struct mat2 {
    int A[2][2];
    mat2() {
    }
    mat2(int a, int b, int c, int d) {
        A[0][0] = a;
        A[0][1] = b;
        A[1][0] = c;
        A[1][1] = d;
    }
    mat2 operator*(const mat2 &otr) {
        mat2 ans(0, 0, 0, 0);
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                for(int k=0; k<2; k++) {
                    ans.A[i][j] = (ans.A[i][j] + A[i][k] * otr.A[k][j])%mod;
                }
            }
        }
        return ans;
    }
    par operator*(const par &w) {
        return par((w.f * A[0][0] + w.s * A[1][0])%mod, (w.f * A[0][1] + w.s * A[1][1])%mod);
    }
};

mat2 bas(0, 1, 1, 1), ido(1, 0, 0, 1);
int pots[5] = {1, 10, 100, 1000, 10000};

mat2 expBin(int n) {
    if(n==0)
        return ido;
    if(n==1)
        return bas;
    mat2 mit = expBin(n/2);
    if(n%2)
        return mit*mit*bas;
    else
        return mit*mit;
}

void testCase() {
    int a, b, n, m;
    scanf("%d%d%d%d", &a, &b, &n, &m);
    mod = pots[m];

    if(n==0)
        printf("%d\n", a%mod);
    else if(n==1)
        printf("%d\n", b%mod);
    else {
        mat2 mato = expBin(n-1);
        par ans = mato*par(a,b);
        printf("%d\n", ans.s);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
