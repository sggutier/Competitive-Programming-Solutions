#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int mod = 1e9 + 7;

void makeTab(int N, char* str, int* prevo) {
    int i=-1, j=0;
    prevo[0] = -1;
    while(j<N) {
        while(i!=-1 && str[j]!=str[i])
            i = prevo[i];
        i++, j++;
        prevo[j] = i;
    }
}

void kmp(int N, char* str, int M, char* sch, int* prevo, int* mtchs) {
    int i=0, j=0;
    prevo[0] = -1;
    while(j<N) {
        while(i!=-1 && str[j]!=sch[i])
            i = prevo[i];
        i++, j++;
        if(i==M) {
            mtchs[j-1] = j;
            i = prevo[i];
        }
    }
}

int N, M;
char S[limN], T[limN];
int dp[limN], dps[limN];
int sigMtch[limN];

int main() {
    int ant[limN];
    
    scanf("%s%s", S, T);
    N = strlen(S);
    M = strlen(T);

    makeTab(M, T, ant);
    kmp(N, S, M, T, ant, sigMtch);
    sigMtch[N] = N;
    for(int i=N-1; i>=0; i--) {
        if(sigMtch[i]) {
            sigMtch[i]--;
            continue;
        }
        sigMtch[i] = sigMtch[i+1];
    }

    for(int i=N-1; i>=0; i--) {
        dp[i] = dp[i+1];
        if(i+M > N)
            continue;
        int j = sigMtch[i+M-1];
        if(j!=N)
            dp[i] = ( (dp[i] + dps[j+1])%mod + (N-j) )%mod;
        dps[i] = (dp[i] + dps[i+1])%mod;
    }

    printf("%d\n", dp[0]);
}
