#include <bits/stdc++.h>
using namespace std;
const int limN = 60;

int N;
long long NBL, NBR;
long long adjL[2*limN], adjR[2*limN];
int maxAns;
long long ansMskL, ansMskR;

void bruta(int pos=0, long long mskL=0LL, long long mskR=0LL, int cnt=0, long long usdL=0, long long usdR=0) {
    if(mskL==NBL && mskR==NBR) {
        if(cnt > maxAns) {
            maxAns = cnt;
            ansMskL = usdL;
            ansMskR = usdR;
        }
        return;
    }
    for(int i=pos; i<N; i++) {
        if(i<limN? !((1LL<<i) & mskL) : !((1LL<<(i-limN)) & mskR)) {
            if(i < limN)
                bruta(i+1, mskL | adjL[i], mskR | adjR[i], cnt+1, usdL | (1LL<<i), usdR);
            else
                bruta(i+1, mskL | adjL[i], mskR | adjR[i], cnt+1, usdL, usdR | (1LL<<(i-limN)));
        }
    }
}

void testCase() {
    maxAns = 0;
    
    int E;
    scanf("%d%d", &N, &E);
    NBL = (1LL<<min(limN, N))-1;
    NBR = (1LL<<max(0, N-limN))-1;
    for(int i=0; i<N; i++) {
        adjR[i] = adjL[i] = 0;
        if(i<limN)
            adjL[i] |= (1LL<<i);
        else
            adjR[i] |= (1LL<<(i-limN));
    }
    while(E--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        if(b < limN)
            adjL[a] |= (1LL<<b);
        else
            adjR[a] |= (1LL<<(b-limN));
        if(a < limN)
            adjL[b] |= (1LL<<a);
        else
            adjR[b] |= (1LL<<(a-limN));
    }
    bruta();

    printf("%d\n", maxAns);
    maxAns = 0;
    for(int i=0; i<limN; i++) {
        if((1LL<<i) & ansMskL) {
            if(maxAns++)
                printf(" ");
            printf("%d", i+1);
        }
    }
    for(int i=0; i<limN; i++) {
        if((1LL<<i) & ansMskR) {
            if(maxAns++)
                printf(" ");
            printf("%d", i+limN+1);
        }
    }
    printf("\n");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
