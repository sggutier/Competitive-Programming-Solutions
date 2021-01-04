#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1005;
const double TRD = 1 / 3.0;
const double QRT = 1 / 4.0;

double _z[LIM_N], _z2[LIM_N];
double a[LIM_N], b[LIM_N], c[LIM_N];

void calcVals(double *d, int N, double *x) {
    for(int i=N-2; i; i--) {
        a[i] = c[i] = QRT;
        b[i] = -3 * QRT;
        d[i] = -1 - d[i] * QRT;
    }
    c[0] = TRD;
    b[0] = -2 * TRD;
    d[0] = -1 -d[0] * TRD;
    a[N-1] = c[0];
    b[N-1] = b[0];
    d[N-1] = -1 -d[N-1] * TRD;
    // for(int i=0; i < N; i++)
    //     printf("%.4lf ", a[i]);
    // printf("\n");
    // for(int i=0; i < N; i++)
    //     printf("%.4lf ", b[i]);
    // printf("\n");
    // for(int i=0; i < N; i++)
    //     printf("%.4lf ", c[i]);
    // printf("\n");
    // for(int i=0; i < N; i++)
    //     printf("%.4lf ", d[i]);
    // printf("\n");

    for(int i=1; i < N; i++) {
        double w = a[i] / b[i-1];
        b[i] -= w * c[i-1];
        d[i] -= w * d[i-1];
    }
    x[N-1] = d[N-1] / b[N-1];
    for(int i=N-2; i >= 0; i--) {
        x[i] = (d[i] - c[i] * x[i+1]) / b[i];
    }
}

int main() {
    int R, C ;
    int x, y ;
    double *z = _z, *z2 = _z2;
    cin >> R >> C ;
    cin >> x >> y ;
    x = R-x;
    y--;
    if(C == 1) {
        cout << 2*x << endl;
        return 0 ;
    }

    for(int i=0; i < x; i++) {
        calcVals(z, C, z2);
        swap(z, z2);
    }
    printf("%.10lf\n", z[y]);
}
