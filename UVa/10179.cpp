#include <bits/stdc++.h>
using namespace std;
const int limP = 1e6;
#define par pair<int,int>
#define f first
#define s second

vector <bool> comp(limP);
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

int phi(int n) {
    int ans = 1;
    for(const int &p:primos) {
        if(p>n)
            break;
        if(n%p)
            continue;
        n /= p;
        int a=p, b=1;
        while(n%p==0) {
            n /= p;
            b = a;
            a *= p;
        }
        ans *= (a-b);
    }
    if(n>1) {
        int w = sqrt(n);
        if(w*w==n)
            ans *= (n-w);
        else
            ans *= (n-1);
    }
    return ans;
}

int main() {
    criba();
    int n;

    while(scanf("%d", &n)!=EOF &&n) {
        printf("%d\n", phi(n));
    }
    
    return 0;
}
