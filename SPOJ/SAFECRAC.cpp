#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10;
const ll mod = 1e9 + 7;

struct Matr {
    vector < vector <ll> > vals;
    Matr() {
        vals.assign(N, vector<ll>(N));
    }
    Matr operator*(const Matr &otr) {
        Matr ans;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<N; k++)
                    ans.vals[i][j] = (ans.vals[i][j] + vals[i][k] * otr.vals[k][j]) % mod;
        return ans;
    }
    void printa() {
        printf("Matriz es:\n");
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                printf("%lld ", vals[i][j]);
            printf("\n");
        }
        printf("----\n");
    }
};

Matr bas, uno;

Matr expBin(int X) {
    if(X==0)
        return uno;
    if(X==1)
        return bas;
    // printf("Calculando %d\n", X);
    Matr mt = expBin(X/2);
    return X%2? mt*mt*bas : mt*mt;
}

void testCase(int n) {
    Matr M = expBin(n-1);
    ll ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            ans = (ans + M.vals[i][j]) % mod;
    printf("%lld\n", ans);
}

int main() {
    for(int i=0; i<N; i++)
        uno.vals[i][i] = 1;
    bas.vals[0][7] = 1;
    bas.vals[1][2] = bas.vals[1][4] = 1;
    bas.vals[2][1] = bas.vals[2][3] = bas.vals[2][5] = 1;
    bas.vals[3][2] = bas.vals[3][6] = 1;
    bas.vals[4][1] = bas.vals[4][5] = bas.vals[4][7] = 1;
    bas.vals[5][2] = bas.vals[5][4] = bas.vals[5][6] = bas.vals[5][8] = 1;
    bas.vals[6][3] = bas.vals[6][5] = bas.vals[6][9] = 1;
    bas.vals[7][4] = bas.vals[7][8] = bas.vals[7][0] = 1;
    bas.vals[8][5] = bas.vals[8][7] = bas.vals[8][9] = 1;
    bas.vals[9][6] = bas.vals[9][8] = 1;
    int tc ;
    scanf("%d", &tc);
    for(int i=0, n; i<tc; i++) {
        scanf("%d", &n);
        testCase(n);
    }
}
