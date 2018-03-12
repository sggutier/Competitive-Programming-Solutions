/*
ID: me60
LANG: C++11
TASK: holstein
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    
    int vitNum;
    int* vitReq;
    int feedTyp;
    int** feeds;
    pair<int,int> ans ((1<<30), 0);

    scanf("%d", &vitNum);
    vitReq = new int[vitNum];
    for(int i=0; i<vitNum; i++)
        scanf("%d", &vitReq[i]);
    scanf("%d", &feedTyp);
    feeds = new int*[feedTyp];
    for(int i=0; i<feedTyp; i++)  {
        feeds[i] = new int[vitNum];
        for(int j=0; j<vitNum; j++) { 
            scanf("%d", &feeds[i][j]);
        }
    }

    for(int b=0; b<(1<<feedTyp); b++) {
        int typCnt = 0;
        int feedSum[vitNum];
        bool itWorks = true;
        memset(feedSum, 0, sizeof(feedSum));
        for(int i=0; i<feedTyp; i++) {
            if((1<<i) & b) {
                typCnt ++;
                for(int j=0; j<vitNum; j++)
                    feedSum[j] += feeds[i][j];
            }
        }
        for(int i=0; i<vitNum; i++)
            if(feedSum[i]<vitReq[i])
                itWorks = false;
        if(itWorks)
            ans = min(ans, make_pair(typCnt, b));
    }

    printf("%d", ans.first);
    for(int i=0; i<feedTyp; i++)
        if((1<<i) & ans.second)
            printf(" %d", i+1);
    printf("\n");
    
    return 0;
}
