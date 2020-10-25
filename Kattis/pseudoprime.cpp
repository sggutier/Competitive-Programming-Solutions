#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limP = 32000;

bool isComp[limP];
vector<int> prims;

void criba() {
        isComp[0] = isComp[1] = true;
        for(int i=2; i*i<limP; i++)
                if(!isComp[i])
                        for(int j=i*i; j<limP; j+=i)
                                isComp[j] = true;
        for(int i=2; i<limP; i++)
                if(!isComp[i])
                        prims.push_back(i);
}

ll mod ;

ll expBin(const ll bas, const ll n) {
        if(n == 0) {
                return 1 ;
        }
        ll mit = expBin(bas, n>>1);
        if(n & 1)
                return (((mit*mit) % mod) * bas) % mod;
        return ((mit*mit) % mod) ;
}

bool isPrime(const int b) {
        for(const int p : prims) {
                if(p >= b) {
                        break;
                }
                if(b % p == 0) {
                        return false;
                }
        }
        return true;
}

int main() {
        criba();
        ll a, b ;
        while(scanf("%lld%lld", &a, &b) != EOF && (a || b)) {
                mod = a;
                printf("%s\n", !isPrime(a) && expBin(b, a) == b? "yes" : "no");
        }
}
