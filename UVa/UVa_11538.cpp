#include <bits/stdc++.h>
using namespace std;

long long gauss(long long k) {
    if(k%2LL==0LL)
        return (k/2LL)*(k+1);
    else
        return ((k+1)/2LL)*k;
}

long long ssum(unsigned long long k) {
    return (k*(k+1)*(2*k+1))/6LL;
}

long long testCase(long long N, long long M) {
    if(N>M)
        swap(N, M);
    long long ans = 0LL;
    // for(int i=2; i<=N; i++)
    ans += M*gauss(N-1)*2LL;
    ans += N*gauss(M-1)*2LL;
    ans += 4LL * ( (N-1)*(N*M + N + M + 1) - (N + M + 2) * (gauss(N)-1) + (ssum(N)-1) );
    return ans;
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && a!=0 && b!=0)
        printf("%lld\n", testCase(a, b));
    
    return 0;
}
