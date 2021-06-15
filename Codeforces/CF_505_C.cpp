#include <bits/stdc++.h>
using namespace std;
const int limN = 30000 + 5;
const int limR = 2200;

unsigned short dp[limN][limR];
bool usd[limN][limR];
int fruitCnt[limN];

unsigned short memo(const int pos, const int stp) {
    if(pos >= limN)
        return 0 ;
    if(stp < limR) {
        if(usd[pos][stp])
            return dp[pos][stp];
        usd[pos][stp] = true;
    }
    unsigned short ans = 0;
    if(stp > 1)
        ans = memo(pos+stp-1, stp-1);
    ans = max(ans, memo(pos + stp, stp));
    ans = max(ans, memo(pos + stp + 1, stp+1));
    ans += fruitCnt[pos];
    if(stp < limR)
        dp[pos][stp] = ans;
    return ans;
}

int main() {
    int N, D ;

    scanf("%d%d", &N, &D);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        fruitCnt[a] ++;
    }

    printf("%d\n", memo(D, D));
}
