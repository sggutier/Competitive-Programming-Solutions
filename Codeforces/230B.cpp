#include <bits/stdc++.h>
using namespace std;
const int limP = 1e6 + 5;

bool comp[limP];

void criba(int n=limP) {
    comp[0] = comp[1] = true;
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
}

int main() {
    criba();
    int querCnt;

    scanf("%d", &querCnt);
    while(querCnt--) {
        long long n, r;
        scanf("%lld", &n);
        r = sqrt(n);
        printf("%s\n", (r*r==n && !comp[r])? "YES" : "NO");
    }
}
