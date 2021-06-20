#include <bits/stdc++.h>
using namespace std;
const long long mili = 1e6;
const long long dos = 2e3;

int main() {
    long long a, b, c, d, sum, prod, x, y;
    int cnt = 0;
    for(a=1; a<=dos; a++) {
        for(b=a; a+b<=dos; b++) {
            for(c=b; a+b+c<=dos; c++) {
                prod = a*b*c, sum = a+b+c;
                x = prod-mili, y = mili*sum;
                if(x<=0 || y%x!=0)
                    continue;
                d = y/x;
                if(d<c || a+b+c+d>dos)
                    continue;
                cnt ++;
                printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
            }
        }
    }
    
    return 0;
}
