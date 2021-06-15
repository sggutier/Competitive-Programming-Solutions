#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// d^2 + (p-q)^2 = (p+q)^2
// d^2 + p^2 - 2pq+ q^2 = p^2 + 2pq + q^2
// d^2 - 2pq = 2pq
// d^2 = 4pq
// q = d^2 / (4p)


int lastT ;

void relax(int i, int j, vector <ll> &xs, vector <long double> &rs, vector <int> &ss) {
    int t = ss[j];
    long double lv = rs[i];
    rs[i] = min(rs[i], (xs[i] - xs[t]) * (xs[i] - xs[t]) / (4 * rs[t]));
    if(rs[i] != lv) {
        lastT = j ;
    }
}

long double solve(vector <ll> &xs, vector <ll> &ps, int maxRev = 1e6) {
    vector <long double> rs;
    vector <int> ss;
    int N = xs.size();
    long double sum = 0 ;
    lastT = -1 ;
    for(int i=0; i < N; i++) {
        rs.push_back(ps[i]);
        int maxK = min(maxRev, (int) ss.size());
        for(int j=0; j < maxK; j++) {
            relax(i, ss.size() - j - 1, xs, rs, ss);
        }
        // if(i == N-1) {
        //     printf("%.5lf => (%d)\n\t", rs[i], maxK);
        //     for(int j=0; j < maxK; j++) {
        //         printf("(%d %.3lf) ", (int) ss.size() - j - 1, rs[ss.size() - j - 1]);
        //     }
        //     printf("\n");
        // }
        while(!ss.empty() && rs[ss[ss.size() - 1]] <= rs[i]) {
            ss.pop_back();
        }
        // printf("%.4Lf ", rs[i]);
        ss.push_back(i);
        sum += rs[i];
    }
    // printf("\n");
    // printf("%d\n", lastT);
    // printf("%d => %.9Lf\n", (int) ss.size(), rs[ss[0]]);
    return sum ;
}

int main() {
    int N ;
    vector <ll> xs, ps;
    // scanf("%d", &N);
    N = 500 ;
    int K = 304;
    xs.push_back(0);
    ps.push_back(1e6);
    for(ll q=2, x=0, d; q <= N; q++) {
        if(q == N) {
            d = q + 1  + 63246 ;
            x += d ;
            xs.push_back(x);
            ps.push_back(1e6);
            break;
        }
        // d = ceil(sqrt(4*p*q*0.25*0.25));
        d = q ;
        x += d ;
        // xs.push_back(x);
        // ps.push_back(ceil(q * 0.25));
        // p = q ;
        xs.push_back(x);
        ps.push_back(1e6);
    }
    reverse(xs.begin(), xs.end());
    reverse(ps.begin(), ps.end());

    while(xs.size() - K) {
        xs.pop_back();
        ps.pop_back();
    }
    N = K ;
    for(int i=N-1; i >= 0; i--) {
        // xs[i] += xs[i-1];
        xs[i] = xs[0] - xs[i];
    }
    // ps[0] = 1000;
    ps[1] = 1000;
    xs[N-1] = xs[N-2] + pow(10, 3.5);
    ps[N-1] = 1e6 ;
    // printf("%d\n", (int) xs.size());

    printf("%d\n", N);
    for(int i=0; i < N; i++) {
        printf("%lld %lld\n", xs[i], ps[i]);
    }

    // printf("%.9Lf\n", solve(xs, ps));
    // printf("%.9Lf\n", solve(xs, ps, 300));
}
