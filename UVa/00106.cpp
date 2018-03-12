#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 1;

bitset <limN> udo;

void genera(int n, int &ans, int &p) {
    udo.reset();
    ans = 0;
    p = 0;
    for(int a=1; 2*a*a <= n; a++) {
        for(int b=a+1; a*a + b*b <=n; b+=2) {
            if(__gcd(a,b) > 1)
                continue;
            int x = b*b - a*a, y = 2*a*b, z = a*a + b*b;
            for(int k=1; k*z <=n; k++) 
                udo[k*x] = udo[k*y] = udo[k*z] = true;
            ans ++;
        }
    }
    for(int i=1; i<=n; i++)
        if(!udo[i])
            p++;
}

int main() {
    int x, y, n;
    while(scanf("%d", &n)!=EOF) {
        genera(n, x, y);
        printf("%d %d\n", x, y);
    }
}
