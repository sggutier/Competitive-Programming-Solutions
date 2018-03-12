#include <bits/stdc++.h>
using namespace std;

double testCase(double a, double b, double rem) {
    double n = a+b;    
    return (a/n)*(b/(a+b-rem-1)) + (b/n)*((b-1)/(a+b-rem-1));
}

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF)
        printf("%.5lf\n", testCase(a,b,c));
}
