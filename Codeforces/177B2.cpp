#include <bits/stdc++.h>
using namespace std;
const int limN = 32000;

bool comp[limN];
vector <int> primos;

void criba(int n = limN) {
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            primos.push_back(i);
}

long long testCase(int n) {
    long long ans = 0;

    ans += n;
    for(const int &p:primos) {
        if(p > n) break;
        while(n%p==0) {
            // printf("%d %d %d\n", p, n, n/p);
            ans += n/p;
            n /= p;
        }
    }
    if(n>1)
        ans ++;

    return ans;
}

int main() {
    criba();
    int n;
    
    scanf("%d", &n);
    printf("%lld\n", testCase(n));

    // for(int i=1; i<=50; i++)
    //     printf("%d %lld\n", i, testCase(i));
}
