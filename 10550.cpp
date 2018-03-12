#include <bits/stdc++.h>
using namespace std;

int dif(int a, int b) {
    a *= 9;
    b *= 9;
    return (360 + a - b)%360;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d)!=EOF, (a || b || c || d)) {
        printf("%d\n", dif(a, b) + dif(c, b) + dif(c, d) + 1080);
    }

    return 0;
}
