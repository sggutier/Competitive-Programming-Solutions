#include <bits/stdc++.h>
using namespace std;
const int limP = 1e7;

vector<bool> comp(limP);
list <int> primos;

void criba(int n=limP) {
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            primos.push_back(i);
}

long long testCase(long long n) {
    long long ans = -1, ult=-1;
    for(const int &p:primos) {
        if(p>n)
            break;
        if(n%p==0) {
            ult = ans;
            ans = p;
            while(n%p==0)
                n /= p;
        }
    }
    if(n>1) {
        long long w = sqrt(n);
        if(w*w==n) {
            ult = ans;
            ans = w;
        }
        else {
            ult = ans;
            ans = n;
        }
    }
    if(ult==-1)
        ans = -1;
    return ans;
}

int main() {
    criba();
    long long n;

    while(scanf("%lld", &n)!=EOF && n) {
        printf("%lld\n", testCase(abs(n)));
    }
    
    return 0;
}
