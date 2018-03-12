#include <bits/stdc++.h>
using namespace std;
#define par pair<double, double>
#define x first
#define y second
const double r3 = sqrt(3.0);
const double invR3 = 1/r3;

inline double dst(const par &A, const par &B) {
    return hypot(A.x - B.x, A.y - B.y);
}

inline double dy(const int r) {
    return (r/2.0)*r3;
}

inline double dx(const int r) {
    return r/2.0;
}

par coord(int N) {
    int r = sqrt(N), c = N-r*r;
    r++;
    if(c%2==0)
        return par( -dx(r) + 0.5 + c/2.0, dy(r) - invR3/2.0 );
    else
        return par( -dx(r-1) + c/2.0, dy(r-1) + invR3/2.0 );
}

double testCase(int a, int b) {
    return dst(coord(a), coord(b));
    // par A = coord(a), B = coord(b);
    // printf("%.3lf %.3lf\n", A.x, A.y);
    // printf("%.3lf %.3lf\n", B.x, B.y);
    // return dst(A, B);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        printf("%.3lf\n", testCase(a,b));
}
