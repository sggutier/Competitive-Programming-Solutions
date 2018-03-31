#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bitset <limN> isComp;
vector <int> primos;

void criba(int N = limN) {
    isComp[0] = isComp[1] = true;
    for(int i=2; i*i<N; i++)
        if(!isComp[i])
            for(int j=i*i; j<N; j+=i)
                isComp[j] = true;
    for(int i=2; i<N; i++)
        if(!isComp[i])
            primos.push_back(i);
}

bool usd[5005];
int minCMemo[5005];
map <int, bool> esPMemo;

bool isPrim(int n) {
    if(n < limN)
        return !isComp[n];
    auto it = esPMemo.find(n);
    if(it!=esPMemo.end())
        return it->second;
    for(const int &p:primos) {
        if(n % p == 0) {
            return esPMemo[n] = false;
        }
    }
    return esPMemo[n] = true;
}

int minC(int n) {
    if(n <= 5000 && usd[n])
        return minCMemo[n];
    if(n <= 5000)
        usd[n] = true;
    // printf("%d\n", n);
    int ans = n;
    if(isPrim(n)) {
        ans = 1;
    }
    else {
        if(n <= 5000) {
            for(int d=2; d+2<=n; d++) {
                ans = min(ans, minC(d) + minC(n-d));
            }
        }
        else {
            for(int d=2; d <= 5000; d++)
                if(isPrim(n-d))
                    ans = min(ans, 1 + minC(d));
        }
    }
    if(n <= 5000)
        minCMemo[n] = ans;
    // printf("%d => %d\n", n, ans);
    return ans;
}

int main() {
    criba();
    int n ;
    scanf("%d", &n);
    printf("%d\n", minC(n));
}
