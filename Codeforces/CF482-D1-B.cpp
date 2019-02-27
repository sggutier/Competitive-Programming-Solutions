#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N, K ;
int ls[limN], rs[limN], qs[limN];
int ans[limN];
int mks[limN], sms[limN];

int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) {
        scanf("%d%d%d", &ls[i], &rs[i], &qs[i]);
    }

    for(int b=0; b<30; b++) {
        memset(mks, 0, sizeof(mks));
        for(int i=0; i<K; i++)
            if((1<<b) & qs[i]) {
                mks[ls[i]]++;
                mks[rs[i]+1] --;
            }
        for(int i=1, c=0; i<=N; i++) {
            c += mks[i];
            sms[i] = sms[i-1];
            if(c) {
                ans[i] |= 1<<b;
                sms[i] ++;
            }            
        }
        for(int i=0; i<K; i++)
            if( ((1<<b) & qs[i]) == 0 && sms[rs[i]] - sms[ls[i]-1] == rs[i]-ls[i]+1) {
                printf("NO\n");
                return 0 ;
            }
    }

    printf("YES\n");
    for(int i=1; i<=N; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
