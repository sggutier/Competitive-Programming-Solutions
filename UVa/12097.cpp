#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const double PI = acos(-1);

ll cnt(vector <double> &v, double r) {
    ll ans = 0 ;
    for(const double k : v)
        ans += (ll) (k / r) ;
    return ans;
}

void testCase() {
    int N ;
    ll K ;
    vector <double> pies;
    scanf("%d%lld", &N, &K);
    K ++ ;
    double a ;
    for(int i=0; i < N; i++) {
        scanf("%lf", &a);
        pies.push_back(a*a*PI);
    }

    double ini=0, fin=4e12;
    while(ini + 1e-6 < fin ) {
        double piv = (ini + fin) / 2 ;
        if(cnt(pies, piv) >= K) {
            ini = piv ;
        }
        else
            fin = piv ;
    }

    printf("%.4lf\n", ini);
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
}
