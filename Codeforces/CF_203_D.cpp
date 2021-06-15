#include <bits/stdc++.h>
using namespace std;

double colTim(double x, double maxX, double dx) {
    if(dx == 0)
        return 1e15;
    if(dx < 0)
        return -x / dx;
    else
        return (maxX - x) / dx ;
}

double igs(double a, double b) {
    return fabs(a-b) < 1e-6 ;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    double x, y, z ;
    double dx, dy, dz;
    double a, b, c ;
    cin >> a >> c >> b ;
    cin >> dx >> dy >> dz ;
    x = a / 2 ;
    y = b ;
    z = 0 ;
    while(!igs(y, 0)) {
        // printf("%.3lf %.3lf %.3lf\n", x, y, z);
        // printf("\t%.3lf %.3lf %.3lf\n", dx, dy, dz);
        double t = min(colTim(x, a, dx), min(colTim(y, b, dy), colTim(z, c, dz)));
        // printf("\t%.3lf\n", t);
        double novX = x + dx*t;
        double novY = y + dy*t;
        double novZ = z + dz*t;
        if(igs(novX, 0) || igs(novX, a)) {
            dx *= -1;
        }
        if(igs(novZ, 0) || igs(novZ, c)) {
            dz *= -1;
        }
        x = novX;
        y = novY;
        z = novZ;
    }
    printf("%.9lf %.9lf\n", x, z);
}
