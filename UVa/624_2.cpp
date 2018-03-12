#include <bits/stdc++.h>
using namespace std;

void testCase(int maxLen, int songNum) {
    pair <int,int> ans (0, 0);
    int songDur[songNum];
    for(int i=0; i<songNum; i++)
        scanf("%d", &songDur[i]);

    for(int i=(1<<songNum)-1; i>=0; i--) {
        int sum = 0;
        for(int j=0; j<songNum; j++)
            if((1<<j) & i)
                sum += songDur[j];
        if(sum<=maxLen)
            ans = max(ans, make_pair(sum, i));
    }

    for(int i=0; i<songNum; i++)
        if((1<<i) & ans.second)
            printf("%d ", songDur[i]);
    printf("sum:%d\n", ans.first);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
