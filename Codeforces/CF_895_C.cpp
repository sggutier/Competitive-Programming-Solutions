#include <bits/stdc++.h>
using namespace std;
const int limN = 71;
const int mod = 1e9 + 7;
const int P = 19;
const int limP = 1<<P;
const int limW = 1e5 + 5;

vector<int> primos = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};

int cnt[limN];
int msk[limN];
int memo[limN][limP];
long long pots2[limW];
bool usd[limN][limP];

int calca(int n=limN-1, int m = 0) {
    if(n <= 0)
        return m == 0;
    if(usd[n][m])
        return memo[n][m];
    usd[n][m] = true;
    int &ans = memo[n][m];
    if(cnt[n] == 0) {
        return ans = calca(n-1, m);
    }
    ans = (ans + pots2[cnt[n]-1] * calca(n-1, m)) % mod;
    ans = (ans + pots2[cnt[n]-1] * calca(n-1, m ^ msk[n] ) ) % mod;
    return ans;
}

int main() {

    for(int i=1; i<limN; i++) {
        int m = 0;
        for(int n=i, j=0; j<P; j++) {
            while(n % primos[j] ==  0) {
                n /= primos[j];
                m ^= (1<<j);
            }
        }
        msk[i] = m;
    }
    pots2[0] = 1;
    for(int i=1; i<limW; i++)
        pots2[i] = (2*pots2[i-1]) % mod;

    int N ;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }

    printf("%d\n", (calca() + mod - 1) % mod);
}
