#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
typedef long long ll;
const int limN = 1e6 + 5;

int f(int n) {
    int ans = 1;
    while(n) {
        if(n%10)
            ans *= n%10;
        n /= 10;
    }
    return ans;
}

int dp[limN];

int g(int n) {
    if(n < 10)
        return n;
    if(dp[n])
        return dp[n];
    return dp[n] = g(f(n));
}

int cnt[limN][10];

int main() {
    for(int i=1; i<limN; i++) {
        int w = g(i);
        for(int j=0; j<10; j++)
            cnt[i][j] = cnt[i-1][j];
        cnt[i][w] ++;
    }
    int Q ;

    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", cnt[b][c] - cnt[a-1][c]);
    }
}
