#include <bits/stdc++.h>
using namespace std;
const int limN = 32000;

vector <int> primos;
bitset <limN> isComp;

void criba(int N = limN) {
    for(int i=2; i*i<N; i++)
        if(!isComp[i])
            for(int j=i*i; j<N; j+=i)
                isComp[j] = true;
    for(int i=2; i<N; i++)
        if(!isComp[i])
            primos.push_back(i);
}

set <int> divos;

void factoriza(int n) {
    for(const int p : primos) {
        if(p > n) break;
        if(n % p) continue;
        while(n % p == 0)
            n /= p;
        divos.insert(p);
    }
    if(n > 1) {
        int q =sqrt(n);
        divos.insert(q*q==n? q : n);
    }
}

map <int, int> dp;

int grundy(int msk) {
    if(msk==0)
        return 0;
    auto it = dp.find(msk);
    if(it != dp.end())
        return it->second;
    int maxbt = 0;
    int mex = 0;
    for(int i=0; i<31; i++) {
        if((1<<i) & msk) {
            maxbt = i;
        }
    }
    for(int i=0; i<=maxbt; i++) {
        int otr = msk & ((1<<i) - 1);
        mex |= 1<<grundy( otr | (msk >> (i+1)) );
    }
    for(int i=0; ; i++) {
        if((1<<i) & mex) continue;
        return dp[msk] = i;
    }
    return 0;
}

int main() {
    criba();
    int g = 0;
    int N ;
    int arr[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        factoriza(arr[i]);
    }

    for(int p : divos) {
        int msk = 0;
        for(int i=0; i<N; i++) {
            int d = 0, w=arr[i];
            while(w % p==0) {
                w /= p;
                d++;
            }
            if(d)
                msk |= 1<<(d-1);
        }
        g ^= grundy(msk);
    }

    printf("%s\n", g? "Mojtaba" : "Arpa");
}
