#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d;
    double p1, p2, p3;

    cin >> a >> b >> c >> d ;
    p1 = a/b, p2 = c/d;
    p3 = (1-p1)*(1-p2);

    printf("%.9lf\n", p1/(1-p3));
}
