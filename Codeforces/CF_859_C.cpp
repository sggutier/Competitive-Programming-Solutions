#include <bits/stdc++.h>
using namespace std;

int N ;
int nms[55];
int dp[55];
bool usd[55];

int memo(const int pos = 0) {
    if(pos == N) {
        return 0 ;
    }
    if(usd[pos])
        return dp[pos];
    usd[pos] = true;
    return dp[pos] = max(nms[pos] - memo(pos+1), -nms[pos] + memo(pos+1));
}

int main() {
    int tot = 0 ;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nms[i]);
        tot += nms[i];
    }

    int x = memo();
    
    int a = (tot -x ) / 2;
    int b = a+x;

    printf("%d %d\n", a, b);
}
