#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limB = 21;

set <int> ans;
int sigB[22][limN];

int main() {
    int N ;
    int nums[limN];

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        for(int j=0; j<limB; j++) {
            if((1<<j) & nums[i])
                sigB[j][i] = i;
            else
                sigB[j][i] = sigB[j][i-1];
        }
    }

    for(int i=1; i<=N; i++) {
        int pos=i, k = nums[i];
        // printf("%d %d => ", i, nums[i]);
        while(true) {
            // printf("%d ", k);
            ans.insert(k);
            pos --;
            int sp = 0;
            for(int j=0; j<limB; j++) {
                if((1<<j) & k)
                    continue;
                sp = max(sp, sigB[j][pos]);
            }
            if(sp == 0)
                break;
            pos = sp;
            k |= nums[pos];
        }
        // printf("\n");
    }

    printf("%d\n", (int) ans.size());
}
