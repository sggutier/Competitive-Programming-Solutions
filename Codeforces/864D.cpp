#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int N ;
int nums[limN];
int cnt[limN];

int main() {
    int ans = 0;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        cnt[nums[i]]++;
    }

    for(int i=0, t=1; i<N; i++) {
        if(cnt[nums[i]]==1)
            continue;
        while(cnt[t]!=0)
            t++;
        // printf("Buscando poner %d => ", t);
        if(cnt[nums[i]] < 0 || t < nums[i]) {
            cnt[nums[i]] -- ;
            nums[i] = t++;
            ans ++;
        }
        else
            cnt[nums[i]] *= -1;
        // for(int i=0; i<N; i++)
        //     printf("%d ", nums[i]);
        // printf("\n");
    }

    printf("%d\n", ans);
    for(int i=0; i<N; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
