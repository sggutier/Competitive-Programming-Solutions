#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

int N ;
int alts[limN];
int dp[limN][limN];
bool usd[limN][limN];

int minStr(int l=0, int r=N-1, int h=0) {
    if(usd[l][r])
        return dp[l][r];
    usd[l][r] = true;    
    int minH = 1e9 + 7, w = 0;
    for(int i=l; i<=r; i++) {
        minH = min(minH, alts[i]);
    }
    w = minH-h;
    for(int i=l, u=-1; ; i++)  {
        if(u==-1 && alts[i] > minH) {
            u = i;
        }
        else if(u!=-1 && (i>r || alts[i] <= minH)) {
            w += minStr(u, i-1, minH);
            u = -1;
        }
        if(i > r)
            break;
    }
    w = min(w, r-l+1);
    return dp[l][r] = w;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &alts[i]);

    printf("%d\n", minStr());
}
