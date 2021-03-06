#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limP = sqrt(limN);

vector <int> prims;
int divCnt[limN];

void criba(int n = limP) {
    vector <bool> isComp(n);
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i<n; i++)
        if(!isComp[i])
            prims.push_back(i);
}

void desc(int n) {
    for(const int &p:prims) {
        if(p > n) break;
        if(n % p) continue;
        divCnt[p] ++;
        while(n%p==0)
            n /= p;
    }
    if(n > 1)
        divCnt[n]++;
}

int main() {
    criba();
    
    int N ;
    int ans = 1;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        desc(a);
    }

    for(int i=0; i<limN; i++)
        ans = max(ans, divCnt[i]);

    printf("%d\n", ans);
}
