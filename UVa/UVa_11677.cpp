#include <bits/stdc++.h>
using namespace std;
const int minHour = 60;
const int minDay = minHour*24;

inline int testCase(const int &hi, const int &mi, const int &hf, const int &mf) {
    return (minDay + (hf*minHour + mf) - (hi*minHour + mi))%minDay;
}

int main() {
    int a, b, c, d;

    while(scanf("%d%d%d%d", &a, &b, &c, &d)!=EOF && (a || b || c || d)) {
        printf("%d\n", testCase(a,b,c,d));
    }
    
    return 0;
}
