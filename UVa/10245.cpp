#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> par;
#define x first
#define y second
const int limN = 1e4 + 5;

double dst(const par A, const par B) {
    double x = A.x - B.x, y = A.y - B.y;
    return sqrt(x*x + y*y);
}

void testCase(int N) {
    par pts[limN];
    double ans = 1e9;
    set <par> cands;

    for(int i=0; i<N; i++)
        scanf("%lf%lf", &pts[i].x, &pts[i].y);
    if( N <= 1) {
        printf("INFINITY\n");
        return;
    }

    sort(pts, pts+N, [] (par A, par B) { return A.y != B.y? A.y < B.y : A.x < B.y; });

    for(int i=0, j=0; i<N; i++) {
        while(pts[i].y - pts[j].y > ans)
            cands.erase(pts[j++]);
        auto p = cands.lower_bound(pts[i]);
        for(auto it=p; it!=cands.end() && abs(it->x - pts[i].x) <= ans; it++)
            ans = min(ans, dst(*it, pts[i]));
        for(auto it=p; it!=cands.begin(); ) {
            it --;
            if(abs(it->x - pts[i].x) > ans)
                break;
            ans = min(ans, dst(*it, pts[i]));
        }
        p = cands.begin();
        if(p != cands.end())
            ans = min(ans, dst(*p, pts[i]));
        cands.insert(pts[i]);
    }

    if(ans < 10000.0)
        printf("%.4lf\n", ans);
    else
        printf("INFINITY\n");
}

int main() {
    int n ;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}


// #include <bits/stdc++.h>
// using namespace std;

// double dstoo(const double &x1, const double &y1, const double &x2, const double &y2) {
//     double a = x1-x2, b = y1-y2;
//     return a*a + b*b;
// }

// int N;
// double x[40005], y[40005];
// double inf = 1e8;

// void testCase() {
//     double ans = inf + 1;
//     for(int i=0; i<N; i++) {
//         scanf("%lf%lf", &x[i], &y[i]);
//         for(int j=0; j<i; j++) {
//             //printf("%d\n", dst(x[i], y[i], x[j], y[j]));
//             ans = min(ans, dstoo(x[i], y[i], x[j], y[j]));
//         }
//     }
//     //printf("=> %d\n", ans);
//     if(ans>=inf)
//         printf("INFINITY\n");
//     else
//         printf("%.4lf\n", sqrt(ans));
// }

// int main() {
//     while(scanf("%d", &N)!=EOF && N)
//         testCase();
// }
