#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct mat {
    ll arr[2][2];
    mat() {
    }
    mat(int a, int b, int c, int d) {
        arr[0][0] = a;
        arr[0][1] = b;
        arr[1][0] = c;
        arr[1][1] = d;        
    }
        
};

mat operator*(const mat A, const mat B) {
    mat C = {0, 0, 0, 0};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                C.arr[i][j] = (C.arr[i][j] + A.arr[i][k] * B.arr[k][j]) % mod;
    return C ;
}

mat iden = {1, 0, 0, 1};
mat bas ;

mat potMat(ll k) {
    if(k == 0)
        return iden;
    if(k == 1)
        return bas;
    mat mt = potMat(k >> 1);
    return k%2? mt * mt * bas : mt * mt ;
}

int main() {
    ll A, B, x, n;
    cin >> A >> B >> n >> x;
    bas = mat(A, B, 0, 1);
    // for(int k=0; k<=n; k++) {
    //     mat as = potMat(k);
    //     cout << (as.arr[0][0]*x + as.arr[0][1]) % mod << endl;
    // }
    mat res = potMat(n);
    cout << (res.arr[0][0]*x + res.arr[0][1]) % mod << endl;
}
