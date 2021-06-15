#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N ;
int arr[limN];
int cnt[limN];
int minL[limN], maxR[limN];

int main() {
    int maxCnt = 0, minW = 1e9;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        if(!cnt[arr[i]]++)
            minL[arr[i]] = i;
        maxR[arr[i]] = i;
        maxCnt = max(maxCnt, cnt[arr[i]]);
    }

    for(int i=0; i<limN; i++)
        if(cnt[i]==maxCnt)
            minW = min(minW, maxR[i]-minL[i]);

    for(int i=0; i<limN; i++)
        if(cnt[i]==maxCnt && maxR[i]-minL[i] == minW) {
            printf("%d %d\n", minL[i]+1, maxR[i]+1);
            return 0;
        }
}
