#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 9;
const int limM = 4;
const int limN = 32000;

struct Mat4 {
    ll mat[limM][limM];
    Mat4() {}
    Mat4(ll k) : mat {{k, 0, 0, 0}, {1, k+1, 0, 0}, {1, 0, k+1, 0}, {0, 1, 1, k+2}} {}
    void printa() {
        for(int i=0; i<limM; i++) {
            for(int j=0; j<limM; j++)
                printf("%lld ", mat[i][j]);
            printf("\n");
        }
    }
};

Mat4 operator*(const Mat4 &A, const Mat4 &B) {
    Mat4 C;
    for(int i=0; i<limM; i++) {
        for(int j=0; j<limM; j++) {
            ll &w = C.mat[i][j];
            w = 0LL;
            for(int k=0; k<limM; k++)
                w = (w + A.mat[i][k] * B.mat[k][j]) % mod;
        }
    }
    return C;
}

Mat4 operator+(const Mat4 &A, const Mat4 &B) {
    Mat4 C;
    for(int i=0; i<limM; i++) {
        for(int j=0; j<limM; j++) {
            C.mat[i][j] = (A.mat[i][j] + B.mat[i][j]) % mod;
        }
    }
    return C;
}

Mat4 bas;

Mat4 exBin(ll k) {
    if(k==1)
        return bas;
    Mat4 mit = exBin(k/2);
    if(k%2)
        return mit*mit*bas;
    else
        return mit*mit;
}

vector <int> criba(int N = limN) {
    vector <bool> comp(N, false);
    vector <int> prims;
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++)
        if(!comp[i])
            prims.push_back(i);
    return prims;
}

void factoriza(map <int,int> &minP, map <int,int> &maxP, vector <int> &prims, int a, int b) {
    for(const int p:prims) {
        int c = 0, d = 0;
        while(a%p==0) {
            a /= p; c++;
        }
        while(b%p==0) {
            b /= p; d++;
        }
        if(c==0 && d==0)
            continue;
        minP[p] = min(c, d);
        maxP[p] = max(c, d);
    }

    if(b>1) {
        minP[b] = a>1? 1 : 0;
        maxP[b] = 1;
    }
    // printf("\n");
}

int main() {
    vector <int> prims = criba();
    map <int,int> minP, maxP;
    ll k;
    int a, b;
    ll ans = 1;

    scanf("%lld%d%d", &k, &a, &b);
    // cin >> k >> a >> b ;
    
    factoriza(minP, maxP, prims, a, b);
    if(b%a) {
        printf("0\n");
        return 0;
    }
    for(const auto &x:minP) {
        int p = x.first;
        int a = x.second, b = maxP[p];
        // printf("%d => %d %d\n", p, a, b);
        if(a==b)
            continue;
        bas = Mat4(b-a-1);
        // Mat4 tmp = exBin(k);
        // tmp.printa();
        ans = (ans * exBin(k).mat[3][0]) % mod;
    }

    printf("%lld\n", ans);
    // cout << ans << endl;
}
