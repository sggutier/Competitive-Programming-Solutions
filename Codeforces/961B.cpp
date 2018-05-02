#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int A[limN], T[limN];
int sumosL[limN], sumosR[limN];

int main() {
    int N, K ;
    int ans = 0;
    
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    for(int i=1; i<=N; i++)
        scanf("%d", &T[i]);

    for(int i=1; i<=N; i++)
        sumosL[i] = sumosL[i-1] + A[i]*T[i];
    for(int i=N; i>=1; i--)
        sumosR[i] = sumosR[i+1] + A[i]*T[i];
    
    for(int i=1, s=0; i<=N; i++) {
        s += A[i];
        if(i < K) continue;
        s -= A[i-K];
        ans = max(ans,
                  s + sumosR[i+1] + sumosL[i-K]);
    }

    printf("%d\n", ans);
}
