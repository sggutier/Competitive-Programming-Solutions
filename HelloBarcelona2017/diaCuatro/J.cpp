#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> parD;
#define f first
#define s second
const int limN = 1e5 + 5;

void testCase() {
    int N;
    double D ;
    double mic = 1e-6;
    double ans = 0.0, v0=0.0, d0=0.0;
    parD nums[limN];

    scanf("%d%lf", &N, &D);
    D *= 1000;
    for(int i=0; i<N; i++) {
        scanf("%lf%lf", &nums[i].f, &nums[i].s);
    }

    sort(nums, nums+N);
    reverse(nums, nums+N);

    for(int i=0; i<N; i++) {
        if(nums[i].f==0.0)
            continue;
        
        double vf, v, t, a, df;
        a = nums[i].f;
        t = nums[i].s*mic;
        vf = v0 + a*t;
        v = (v0 + vf)/2.0;
        df = d0 + v*t;

        if(df <= D) {
            ans += t;
            d0 = df;
            v0 = vf;
        }
        else {
            double d = D-d0;
            t = (-v0 + sqrt(v0*v0 + 2*a*d))/a;
            ans += t;
            d0 = D;
            break;
        }
    }

    if(d0 < D) {
        ans += (D-d0)/v0;
    }

    printf("%.9lf\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
