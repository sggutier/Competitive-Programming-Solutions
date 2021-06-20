#include <bits/stdc++.h>
using namespace std;

struct Frac {
    int num, den;
    Frac(int a, int b) {
        int g = __gcd(abs(a), abs(b));
        num = a/g;
        den = b/g;
    }
};

bool operator<(const Frac &a, const Frac &b) {    
    return a.num*b.den < b.num*a.den;
}

map < pair <Frac, Frac>, int> reps;
map <int, int> cols;
map <int, int> invos;

void calcPend(int x1, int y1, int x2, int y2) {
    if(x1 == x2) {
        // cols[x1]+=2;
        return;
    }
    if(x1 > x2)
        swap(x1, x2), swap(y1, y2);
    Frac fc(y2-y1, x2-x1);
    Frac fc2(y1*fc.den - fc.num*x1, fc.den);
    // printf("%d %d | %d %d => %d %d (%d %d)\n", x1, y1, x2, y2, fc.num, fc.den, fc2.num, fc2.den);
    reps[{fc, fc2}]++;
}

void testCase() {
    reps.clear();
    cols.clear();
    char tmp[500];
    int x[1000], y[1000];
    int W = 0;
    int ans ;
    while(fgets(tmp, 500, stdin) && sscanf(tmp, "%d%d", &x[W], &y[W])!=EOF) {
        // printf("Linea %s", tmp);
        // printf("%d %d\n", x[W], y[W]);
        cols[x[W]]++;
        W++;
    }
    for(int i=0; i<W; i++)
        for(int j=i+1; j<W; j++)
            calcPend(x[i], y[i], x[j], y[j]);
    ans = min(W, 2);
    for(auto &w:reps) {
        // ans = max(ans, w.second);
        // printf("%d %d | %d %d => %d\n", w.first.first.num, w.first.first.den, w.first.second.num, w.first.second.den, w.second);
        // printf("%d\n", invos[w.second]);
        ans = max(ans, invos[w.second]);
    }
    for(auto &w:cols) {
        ans = max(ans, w.second);
        // printf("Cols %d => %d\n", w.first, w.second);
    }
    // for(int i=0; i<W; i++) {
    //     for(int j=i+1; j<W; j++) {
    //         int c = 2;
    //         for(int k=j+1; k<W; k++) {
    //             if(x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - (y[i]*x[j] + y[j]*x[k] + y[k]*x[i]) == 0)
    //                 c++;
    //         }
    //         ans = max(ans, c);
    //     }
    // }
    printf("%d\n", ans);
}

int main() {
    for(int i=1, s=0; i<=1000; i++) {
        invos[s] = i;
        s += i;
    }
    char tmp[500];
    fgets(tmp, 500, stdin);
    int tc ;
    sscanf(tmp, "%d", &tc);
    fgets(tmp, 500, stdin);
    for(int i=0; i<tc; i++) {
        if(i) printf("\n");
        // printf("Case %d\n", i);
        testCase();
    }
}
