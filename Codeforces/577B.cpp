#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <valarray>

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

int reps[1000];

int main() {
	int N, mod ;
    scanf("%d%d", &N, &mod);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        reps[a%mod] ++;
    }

    if(reps[0]) {
        printf("YES\n");
        return 0 ;
    }

    vd cur(mod);

    for(int i=1; i<mod; i++) {
        if(!reps[i]) continue;
        for(int j=1; j<=reps[i]; j++) {
            cur[(j*i) % mod] = 1;
        }
        reps[i] = 0;
        break;
    }

    for(int i=1; i<mod; i++) {
        if(!reps[i]) continue;
        vd otr(mod), cmb;
        for(int j=1; j<=reps[i]; j++) {
            otr[(j*i) % mod] = 1;
        }
        cmb = conv(cur, otr);
        
        // for(int i=0; i<(int) cur.size(); i++)
        //     cout << cur[i] << " " ;
        // cout << endl;
        // for(int i=0; i<(int) otr.size(); i++)
        //     cout << otr[i] << " " ;
        // cout << endl;
        // for(int i=0; i<(int) cmb.size(); i++)
        //     cout << round(cmb[i]) << " " ;
        // cout << endl;
        // cout << "-----" << endl;
        
        for(int j=cmb.size()-1; j>=0; j--) {
            if(cmb[j] > eps) {
                cur[j%mod] = 1;
            }
        }
        for(int i=0; i<mod; i++)
            if(otr[i] > eps)
                cur[i] = 1;
    }

    printf("%s\n", cur[0] > eps? "YES" : "NO");
        
}
