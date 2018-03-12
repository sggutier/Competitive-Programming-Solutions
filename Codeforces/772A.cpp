#include <bits/stdc++.h>
using namespace std;
#define par pair<long double,long double>
#define g first
#define p second
const long double eps = 1e-9;

bool itWorks(const vector<par> &devs, long double T, long double P) {
    // printf("%lf V\n", T);
    long double zer = 0.0;
    for(const auto &d: devs) {
        long double e = max(zer, d.g - d.p / T);
        // printf("%.3lf ", e);
        if(P - e < zer) {
            // printf("\n");
            return false ;
        }
        P -= e ;
    }
    // printf("\n");
    return true ;
}

int main() {
    int n, P ;
    vector <par> devs ;
    long double sum = 0.0;

    // scanf("%d%d", &n, &P);
    cin >> n >> P ;
    devs = vector<par>(n);
    for(int i=0; i<n; i++) {
        // scanf("%lf%lf", &devs[i].g, &devs[i].p);
        cin >> devs[i].g >> devs[i].p ;
        sum += devs[i].g;
    }

    if(sum - eps<=P) {
        printf("-1\n");
        return 0 ;
    }

    long double ini = 0.0, fin = 1e18;
    while(ini + eps<fin) {
        long double piv = (ini+fin)/2 ;
        if(itWorks(devs, piv, P))
            ini = piv ;
        else
            fin = piv ;
    }

    cout << setprecision(9) << ini << endl;
    
    return 0;
}
