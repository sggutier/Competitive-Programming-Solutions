#include <bits/stdc++.h>
using namespace std;

inline double toFar(double C) {
    return (9.0/5.0)*C + 32.0;
}

inline double toCel(double F) {
    return (5.0/9.0)*(F-32.0);
}

void testCase() {
    double c, i;
    scanf("%lf%lf", &c, &i);
    printf("%.2lf\n", toCel(toFar(c) + i));
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    return 0;
}
