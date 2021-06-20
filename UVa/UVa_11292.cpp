#include <bits/stdc++.h>
using namespace std;

void testCase(int headCnt, int knightCnt) {
    vector <int> heads(headCnt), knights(knightCnt);
    int ans = 0;
    
    for(auto &h: heads)
        scanf("%d", &h);
    for(auto &k: knights)
        scanf("%d", &k);

    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());

    for(int i=0, j=0; i<headCnt; i++) {
        for(; j<knightCnt && knights[j]<heads[i]; j++);
        if(j>=knightCnt) {
            printf("Loowater is doomed!\n");
            return ;
        }
        ans += knights[j++];
    }

    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && a!=0 && b!=0) {
        testCase(a, b);
    }
    
    return 0;
}
