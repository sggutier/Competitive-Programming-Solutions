#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <valarray>
typedef double ld;
const int limN = 1e5 + 5;
const int limK = 30000 + 5;


const double pi2 = 2 * atan2(0, -1);
typedef complex<double> point;
typedef valarray<point > carray;
void fft(carray &a, int sign = +1) {
    int n = a.size(); 
    for (int i = 1, j = 0; i < n - 1; ++i)  {
        for (int k = n >> 1; (j ^= k) < k; k >>= 1); 
        if (i < j) swap(a[i], a[j]);
    } 
    double theta = pi2 * sign; 
    for (int m, mh = 1; (m = mh << 1) <= n; mh = m) {
        point wm(cos(theta / m), sin(theta / m)), w(1, 0);
        for (int i = 0; i < n; i += m, w = point(1, 0))
            for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm) {
                point x = a[j], y = a[k] * w;
                a[j] = x + y;
                a[k] = x - y;
            }
    }
 
    if (sign == -1)
        for (point &p : a) p = p / (1. * n);
}

typedef vector<double> vd;
vd conv(const vd& a, const vd& b) {
    int s = sz(a) + sz(b) - 1, L = 32-__builtin_clz(s), n = 1<<L;
    if (s <= 0) return {};
    carray av(n), bv(n);
    copy(all(a), begin(av)); fft(av, 1);
    copy(all(b), begin(bv)); fft(bv, 1);
    carray cv = av * bv; fft(cv, -1);
    vd c(s); rep(i,0,s) c[i] = cv[i].real();
    return c;
}


vd izq(limK), der(limK), c;
int arr[limN];

ll calca(int l, int r) {
    ll ans = 0;
    // vd c;
    for(int i=l; i<=r; i++)
        der[arr[i]]-=1.0;
    c = conv(izq, der);
    for(int i=l; i<=r; i++) {
        ans += ((ll) round(c[2*arr[i]])) ;
        for(int j=i+1, s; j<=r; j++) {
            s = 2*arr[j] - arr[i];
            if(s >= 0 && s < limK)
                ans += (ll) der[s];
            s = 2*arr[i] - arr[j];
            if(s >= 0 && s < limK)
                ans += (ll) izq[s];
        }
        izq[arr[i]]+=1.0;
    }
    return ans;
}

int main() {
    int N ;
    ll ans = 0;
    int rt ;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        der[arr[i]]+=1.0;
    }
    
    rt = 2500;
    // rt = max(1.0, sqrt(N));
    for(int i=0; i<N; i+=rt) {
        ans += calca(i, min(i+rt-1, N-1));
        // printf("%d %d\n", i, min(i+rt-1, N-1));
    }

    printf("%lld\n", ans);
}
