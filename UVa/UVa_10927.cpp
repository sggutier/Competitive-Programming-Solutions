#include <bits/stdc++.h>
using namespace std;
#define par pair<long long,long long>
#define x first
#define y second
const double EPS = 1e-9;

struct frac {
    long long num, den;
    frac() {
    }
    frac(long long a, long long b) {
        long long c = __gcd(abs(a), abs(b));
        num = a/c;
        den = b/c;
    }
    bool operator < (frac other) const {
        return num*other.den < other.num*den;
    }
    bool operator == (frac other) const {
        return num == other.num && den == other.den;
    }
};

struct pole {
    int height;
    long long nrm;
    par p;
    pair <frac, frac> slop;
    pole() {        
    }
    pole(par _p, int _h) {
        p = _p;
        height = _h;
        long long a=p.x, b=p.y, c;
        a *= a * (a<0LL? -1 : 1);
        b *= b * (b<0LL? -1 : 1);
        c = abs(a)+abs(b);
        nrm = c;
        slop = make_pair(frac(a, c), frac(b, c));
    }
    bool operator < (pole other) const {
        if(slop != other.slop)
            return slop < other.slop;
        if(nrm != other.nrm)
            return nrm < other.nrm;
        return height > other.height;
    }
    bool operator == (pole other) const {
        return slop == other.slop;
    }
};

void testCase(int n) {
    pole poles[n];
    vector<par> ans;
    for(int i=0; i<n; i++) {
        par p;
        int h;
        scanf("%lld%lld%d", &p.x, &p.y, &h);
        poles[i] = pole(p, h);
    }

    sort(poles, poles+n);

    for(int i=1, h=poles[0].height; i<n; i++) {
        // printf("%d %d -> %d -> %d %d\n", (int) poles[i].p.x, (int) poles[i].p.y, (poles[i]==poles[i-1]), poles[i].height, h);
        if(poles[i]==poles[i-1]) {
            if(poles[i].height > h) {
                h = poles[i].height ;
            }
            else {
                ans.push_back(poles[i].p);
            }
        }
        else
            h = poles[i].height;
    }

    sort(ans.begin(), ans.end());

    if(ans.size()==0)
        printf("All the lights are visible.\n");
    else {
        printf("Some lights are not visible:\n");
        for(int i=0; i<(int) ans.size(); i++) {
            printf("x = %lld, y = %lld%c\n", ans[i].x, ans[i].y, i==((int) ans.size())-1? '.' : ';');
        }
    }
}

int main() {
    int tc = 1;
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Data set %d:\n", tc);
        testCase(n);
        tc ++;
    }
}
