#include <bits/stdc++.h>
using namespace std;
const int limP = 1e7;
const int mn = 1e6;

struct BIT {
    int N;
    vector <int> nums;
    void inita(int _n) {
        N = _n+1;
        nums.resize(N, 0);
    }
    void mete(int p, int nov) {
        p++;
        for(; p<N; p+=(p & -p))
            nums[p] += nov;
    }
    int saca(int p) {
        p++;
        int ans = 0;
        for(; p; p-=(p & -p))
            ans += nums[p];
        return ans;
    }
};

bitset <limP> esComp;
vector <int> primos;
vector <int> reprs, nfs;
BIT btF, btC;

void criba(int n = limP) {
    esComp[0] = esComp[1] = true;
    for(int i=2; i*i < n; i++)
        if(!esComp[i])
            for(int j=i*i; j<n; j+=i)
                esComp[j] = true;
    for(int i=2; i<n; i++)
        if(!esComp[i])
            primos.push_back(i);
}

int revo(int n) {
    int pot = mn, ans = 0;
    while(n) {
        ans += (n%10) * pot;
        n /= 10;
        pot /= 10;
    }
    return ans;
}

int numFacs(int n) {
    int ans = 0;
    for(const int &p:primos) {
        if(p*p > n)
            break;
        while(n % p == 0) {
            n /= p;
            ans ++;
        }
    }
    if(n > 1)
        ans ++;
    return ans;
}

void precarga() {
    criba();
    for(int i=mn; i<limP /*&& (int) reprs.size() < 10*/; i++) {
        int w = revo(i);
        if(w < mn && !esComp[w])
            reprs.push_back(i);
    }
    btF.inita(reprs.size());
    btC.inita(reprs.size());
    for(int i=0; i < (int) reprs.size(); i++) {
        // printf("%d => %d\n", r, numFacs(r));
        int w  = numFacs(reprs[i]);
        nfs.push_back(w);
        btF.mete(i, w);
        btC.mete(i, 1);
    }
}

int cuentra(int n) {
    n ++ ;
    int ini=0, fin=reprs.size()-1;
    while(ini < fin) {
        int piv = (ini+fin)/2;
        // printf("\t%d %d\n", piv, btC.saca(piv));
        if(btC.saca(piv) < n)
            ini = piv+1;
        else
            fin = piv;
    }
    // printf("el %d-esimo es %d (%d)\n", n, reprs[ini], btC.saca(ini));
    return ini;
}

int query(int n) {    
    return btF.saca(cuentra(n));
}

void borra(int n) {
    int p = lower_bound(reprs.begin(), reprs.end(), n) - reprs.begin();
    btF.mete(p, -nfs[p]);
    btC.mete(p, -1);
}

int main() {
    precarga();
    char Q[5];
    int n ;
    while(scanf("%s%d", Q, &n)!=EOF) {
        if(Q[0]=='q') {
            printf("%d\n", query(n));
        }
        else {
            borra(n);
        }
    }
}
