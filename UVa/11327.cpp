#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;
const long long limFrac = 12158598919LL;

vector <int> primos;
vector <bool> isComp(limN);
vector <long long> primRelCnt;

int phi(int n) {
    int ans = 1LL;
    for(const int &p:primos) {
        if(n==1) {
            break;
        }
        if(n%p)
            continue;
        int a=1LL;
        while(n%p==0) {
            n/=p;
            a*=p;
        }
        ans *= a - a/p;
    }
    // if(n>1) {
    //     int w = sqrt(n);
    //     ans *= w - 1;
    // }
    return ans;
}

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!isComp[i])
            for(int j=i*i; j<limN; j+=i)
                isComp[j] = true;
    for(int i=2; i<limN; i++)
        if(!isComp[i])
            primos.push_back(i);
}

void precarga(int N=limN) {
    criba();
    long long sumTot = 2LL;
    primRelCnt.push_back(0);
    primRelCnt.push_back(2);
    for(int i=2; i<N; i++) {
        sumTot += phi(i);
        primRelCnt.push_back(sumTot);
        if(sumTot>limFrac) 
            break;
    }
}

void testCase(long long k) {
    int d = lower_bound(primRelCnt.begin(), primRelCnt.end(), k) - primRelCnt.begin();
    k -= primRelCnt[d-1];
    for(int n=0; n<=d; n++) {
        if(__gcd(n,d)!=1)
            continue;
        k --;
        if(k==0) {
            printf("%d/%d\n", n, d);
            return;
        }
    }
}

int main() {
    precarga();
    long long n;

    while(scanf("%lld", &n)!=EOF &&n)
        testCase(n);
    // for(int i=1; i<=200; i++)
    //     cout << phi(i) << endl;
    
    return 0;

}
