#include <bits/stdc++.h>
using namespace std;

double testCase(int d, int r) {
    double a, b;
    a = r/2.0;
    b = sqrt((r*r - d*d)/4.0);
    return a*b*M_PI;
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &a, &b);
        printf("%.3lf\n", testCase(a, b));
    }
}
