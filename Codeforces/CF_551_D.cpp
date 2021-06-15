#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;

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
mat bas = {0, 1, 1, 1};

mat potMat(ll k) {
    if(k == 0)
        return iden;
    if(k == 1)
        return bas;
    mat mt = potMat(k >> 1);
    return k%2? mt * mt * bas : mt * mt ;
}

ll fib(ll n) {
    mat ans = potMat(n+1);
    // for(int i=0; i<2; i++) {
    //     for(int j=0; j<2; j++)
    //         printf("%lld ", ans.arr[i][j]);
    //     printf("\n");
    // }
    return ans.arr[1][1] ;
}

ll pot2(ll k) {
    if(k == 0)
        return 1 ;
    ll mt = pot2(k >> 1);
    return (k%2? mt * mt * 2 : mt * mt) % mod ;
}

bool nofunc(ll k, ll l) {
    while(l && k > 0) {
        l--, k /= 2;
    }
    return k>0;
}

int main() {
    ll n, l ;
    unsigned long long k ;
    cin >> n >> k >> l >> mod ;
    ll ans = 1;
    ll nv ;
    for(int i=0; i<l; i++) {
        if((1ULL << i) & k)
            nv = (pot2(n) - fib(n) + mod ) % mod;
        else
            nv = fib(n);
        ans = (ans * nv) % mod;
    }
    if(nofunc(k, l))
        ans = 0;
    cout << ans%mod << endl;
}
