#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limC = 1e6 + 1;
const int limN = 1e5;

class SegmTree {
private:
    int n;
    vector <par> vals;
    function <par(par, par)> fn;
    par bas;
    par _query(int l, int r) {
        l += n;
        r += n;
        par ans = bas;
        while(l<r) {
            if(l&1)
                ans = fn(ans, vals[l++]);
            if(r&1)
                ans = fn(ans, vals[--r]);
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
public:
    void reset(int _n, par *arr, function <par(par, par)> _fn, par _bas) {
        bas = _bas;
        fn = _fn;
        n = _n;
        vals.resize(2*n);
        for(int i=0; i<n; i++)
            vals[i+n] = arr[i];
        for(int i=n-1; i; i--) {
            vals[i] = fn(vals[i<<1], vals[(i<<1) | 1]);
        }
    }
    par query(int l, int r) {
        return _query(l, r+1);
    }
};

bitset<limC> comp;
SegmTree stMin, stMax;
int primCnt = 0;
int primos[limN];
par diffs[limN];
int ra;

void criba(int N = limC) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;    
    for(int i=2; i<N; i++)
        if(!comp[i])
            primos[primCnt++] = i;
    for(int i=0; i+1<primCnt; i++) {
        diffs[i] = par(primos[i+1] - primos[i], i);
    }
    stMin.reset(primCnt-1, diffs, [](par a, par b) { return a.f!=b.f? (a.f<b.f? a:b) : (a.s<b.s? a:b) ; }, par((1<<30), 0));
    stMax.reset(primCnt-1, diffs, [](par a, par b) { return a.f!=b.f? (a.f>b.f? a:b) : (a.s<b.s? a:b) ; }, par(-(1<<30), 0));
}

bool isPrime(int N) {
    for(int i=0; i<primCnt && primos[i]<N; i++) {
        if(N%primos[i]==0)
            return false;
    }
    return true;
}

void testCase(int L, int R) {
    if(R<=limC) {
        L = lower_bound(primos, primos+primCnt, L) - primos;
        R = upper_bound(primos, primos+primCnt, R) - primos;
        R --;
        if(L>=R) {
            printf("There are no adjacent primes.\n");
            return;
        }
        par ansA = stMin.query(L, R-1);
        par ansB = stMax.query(L, R-1);
        printf("%d,%d are closest, %d,%d are most distant.\n", primos[ansA.s], primos[ansA.s+1], primos[ansB.s], primos[ansB.s+1]);
    }
    else {
        int tmp = primCnt;
        primCnt = ra+1;
        pair<int, par> ansA = make_pair((1<<30), par(0,0));
        pair<int, par> ansB = make_pair(-(1<<30), par(0,0));
        int ult = 0;
        unsigned int A = L, B = R;
        for(unsigned int i=A + (A+1)%2; i<=B; i+=2) {
            if(!isPrime(i))
                continue;
            if(ult) {
                ansA = min(ansA, make_pair(int(i)-ult, par(ult, int(i))));
                ansB = max(ansB, make_pair(int(i)-ult, par(-ult, -int(i))));
            }
            ult = i;
        }
        if(ansA.f==(1<<30))
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", ansA.s.f, ansA.s.s, -ansB.s.f, -ansB.s.s);
        primCnt = tmp;
    }
}

int main() {
    criba();
    int wo = 46340;
    for(int i=0; i<primCnt; i++)
        if(primos[i]<=wo)
            ra = i;
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
}
