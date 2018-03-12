#include <bits/stdc++.h>
using namespace std;
const int limN = 82;

int N;
int vals[limN], msks[limN];

int testCase() {
    int ans = -1;
    for(int i=0; i<N; i++) {
        int a, b, c;
        scanf("%d%d%d%d", &a, &b, &c, &vals[i]);
        msks[i] = (1<<a) | (1<<b) | (1<<c);
        for(int j=0; j<i; j++) {
            if(msks[i] & msks[j])
                continue;
            for(int k=j+1; k<i; k++) {
                if((msks[j] & msks[k]) || (msks[i] & msks[k]))
                    continue;
                ans = max(ans, vals[i] + vals[j] + vals[k]);
            }
        }
    }
    return ans;
}

int main() {
    int tc = 0;
    while(scanf("%d", &N)!=EOF && N)
        printf("Case %d: %d\n", ++tc, testCase());
    
    return 0;
}
