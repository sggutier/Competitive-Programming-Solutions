#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int inf = (1<<30);

int N;
int nums[limN];
int maxDifMem[limN][limN];
bool usd[limN][limN];

int maxDif(int l, int r) {
    if(l>r)
        return 0;
    if(usd[l][r])
        return maxDifMem[l][r];
    usd[l][r] = true ;
    maxDifMem[l][r] = -inf;
    for(int i=l, sum=0; i<=r; i++) {
        sum += nums[i];
        maxDifMem[l][r] = max(maxDifMem[l][r], sum - maxDif(i+1, r));
    }
    for(int i=r, sum=0; i>=l; i--) {
        sum += nums[i];
        maxDifMem[l][r] = max(maxDifMem[l][r], sum - maxDif(l, i-1));
    }
    return maxDifMem[l][r];
}

void testCase() {
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    memset(usd, 0, sizeof(usd));
    printf("%d\n", maxDif(0, N-1));
}

int main() {
    while(scanf("%d", &N)!=EOF && N)
        testCase();
    
    return 0;
}
