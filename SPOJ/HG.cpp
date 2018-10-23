#include <bits/stdc++.h>
using namespace std;
const int limN = 31625;
typedef long long ll;
const ll mod = 1e9 ;
#define f first
#define s second

bitset <limN> isComp;
vector <int> primos;

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!isComp[i])
            for(int j=i*i; j<limN; j+=i)
                isComp[j] = true;
    for(int i=2; i<limN; i++)
        if(!isComp[i])
            primos.push_back(i);
}


void factoriza(map <int, int> &reps, int n) {
    for(const int p : primos) {
        if(n == 1) break;
        if(n % p) continue;
        int w = 0;
        while(n % p == 0) {
            n /= p;
            w ++;
        }
        reps[p] += w;
    }
    if(n > 1)
        reps[n] ++;
}

void rompe(map <int, int> &mp) {
    int N ;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        factoriza(mp, a);
    }
}

int main() {
    criba();
    map <int, int> A, B;
    rompe(A);
    rompe(B);
    ll ans = 1;
    bool g9 = false;
    // for(const auto &e : A)
    //     printf("> %d %d\n", e.f, e.s);
    // for(const auto &e : B)
    //     printf("< %d %d\n", e.f, e.s);
    for(const auto &e : A) {
        int w = min(e.s, B[e.f]);
        while(w--) {
            ans = (ans * e.f) ;
            if(ans >= mod)
                g9 = true;
            ans %= mod;
        }
    }
    printf(g9? "%09lld\n" : "%lld\n", ans);
}
