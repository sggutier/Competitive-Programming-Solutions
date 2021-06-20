#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;

double dst(int a, int b, int x, int y) {
    return hypot(a-x, b-y);
}

bool testCase(int X, int Y, int a, int b) {
    if(X>Y)
        swap(X, Y);
    if(a>b)
        swap(a, b);
    return 2*b<=X && dst(b,b, X-a, Y-a) - (a+b) > -EPS;
}

int main() {
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d)!=EOF && (a || b || c || d))
        printf("%c\n", testCase(a, b, c, d)? 'S' : 'N');
}
