#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int remQ = 60;

inline int queryVal(const int pos) {
    remQ --;
    printf("? %d\n", pos);
    fflush(stdout);
    int x ;
    scanf("%d", &x);
    return x;
}

inline int queryGt(const int x) {
    remQ --;
    int v ;
    printf("> %d\n", x);
    fflush(stdout);
    scanf("%d", &v);
    return v == 1 ;
}

inline void declVal(int x, int d) {
    printf("! %d %d\n", x, d);
    fflush(stdout);
    exit(0);
}

int main() {
    int N ;
    scanf("%d", &N);
    int k = 0;
    set <int> nums;
    for(int i=min(30, N); i > 0; i--)
        nums.insert(queryVal(++k));
    int maxV = *nums.rbegin();
    int ini = maxV, fin = 1e9 ;
    while(ini < fin) {
        int piv = (ini + fin) / 2;
        if(queryGt(piv))
            ini = piv + 1;
        else
            fin = piv;
    }
    maxV = ini;
    nums.insert(maxV);
    for(int i=min(remQ, N - k); i > 0; i--) {
        nums.insert(queryVal(++k));
    }
    int a, b ;
    auto ax = nums.begin();
    a = *ax;
    ax ++;
    b = *ax;
    int d = b-a;
    for(const int x : nums) {
        for(const int y : nums) {
            d = __gcd(d, abs(x-y));
        }
    }
    for(int x = (int) nums.size() == N? d : 1; x <= d; x++) {
        if(d % x) continue;
        int minV = maxV - (N-1) * x;
        if(minV < 0 || a < minV)
            continue;
        declVal(maxV - (N-1) * x, x);
    }
}
