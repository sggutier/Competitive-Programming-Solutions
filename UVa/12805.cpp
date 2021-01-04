#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 500;

bool esComp[LIM_N];
vector <int> primos;

void criba() {
    for(int i=2; i*i < LIM_N; i++)
        if(!esComp[i])
            for(int j=i*i; j < LIM_N; j+=i)
                esComp[j] = true;
    for(int i=3; i < LIM_N; i++)
        if(!esComp[i])
            primos.push_back(i);
}

inline int skn(int n) {
    return (n & 2) == 0;
}

int factor(int n) {
    while((n & 1) == 0) n >>= 1;
    int ans = 0;
    for(const int p : primos) {
        if(p > n) break;
        if(n % p) continue;
        int cnt = 0 ;
        while(n % p == 0) {
            cnt ^= 1;
            n /= p;
        }
        if(cnt) ans ^= skn(p);
    }
    if(n != 1) {
        int sq = sqrt(n);
        if(sq * sq !=  n)
            ans ^= skn(n);
    }
    return ans;
}

int main() {
    criba();
    int tc, n ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &n);
        printf(factor(n)? "-\n" : "+\n");
    }
}
