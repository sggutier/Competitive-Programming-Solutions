#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e6 ;

bool isComp[LIM_N];
bool isDigitPrime[LIM_N + 5];
int sumAcm[LIM_N + 5];

void sieve() {
    isComp[0] = isComp[1] = true;
    for(int i=2; i*i < LIM_N; i++)
        if(!isComp[i])
            for(int j=i*i; j < LIM_N; j+=i)
                isComp[j] = true;
}

void digPs(int pos=0, int sm=0, int pt=1) {
    if(pt >= LIM_N) {
        isDigitPrime[pos] = !isComp[sm];
        return;
    }
    for(int i=0; i < 10; i++)
        digPs(pos + pt*i, sm + i, pt * 10);
}

void init() {
    sieve();
    digPs();
    for(int i=1; i <= LIM_N; i++)
        sumAcm[i] = sumAcm[i-1] + (!isComp[i] && isDigitPrime[i]? 1 : 0);
}

int main() {
    init();
    int N ;
    for(scanf("%d", &N); N; N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", sumAcm[b] - sumAcm[a-1]);
    }
}
