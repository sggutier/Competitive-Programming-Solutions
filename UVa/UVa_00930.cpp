#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 5e4 + 5;

void divideEq(double *P, int &N, double z) {
    for(int i=1; i < N; i++) {
        P[i] += P[i-1] * z;
    }
    N -- ;
}

void testCase(double *P, int N, double *zs) {
    // for(int j=0; j <= N; j++) printf("%lf ", P[j]);
    //     printf("\n");
    for(int i=N-3; i >= 0; i--) {
        divideEq(P, N, zs[i]);
        // for(int j=0; j <= N; j++) printf("%lf ", P[j]);
        // printf("\n");
    }
    double a = P[0], b = P[1], c = P[2];
    double discr = sqrt(b*b - 4*a*c);
    double x0 = (-b - discr) / (2*a);
    double x1 = (-b + discr) / (2*a);
    if(x1 < x0) swap(x0, x1);
    printf("%.1lf\n%.1lf\n", x1, x0);
}

int main() {
    double P[LIM_N], zs[LIM_N];
    int N ;
    int tc ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &N);
        for(int i=0; i <= N; i++) scanf("%lf", &P[i]);
        for(int i=0; i < N-2; i++) scanf("%lf", &zs[i]);
        testCase(P, N, zs);
        // printf("\nDELETE\n");
    }
}
