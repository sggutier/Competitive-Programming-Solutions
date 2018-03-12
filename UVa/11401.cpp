#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;

long long ways[limN+1];

void precarga() {
    for(int n=3; n<=limN; n++) {
        ways[n] = ways[n-1] ;
        long long x = (n-2)/2;
        ways[n] += (x*(x+1))/2;
        if(n%2==0)
            x --;
        ways[n] += (x*(x+1))/2;
    }
}

int main() {
    precarga();
    int n;

    while(scanf("%d", &n)!=EOF && n>=3)
        printf("%lld\n", ways[n]);
    
    return 0;
}
