#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 5;
const int MAX_M = 1e3 + 5;

int nums[MAX_N];
int reps[MAX_M];

void testCase() {
    int N, M, K;
    int ans = MAX_N;
    scanf("%d%d%d", &N, &M, &K);

    memset(reps, 0, sizeof(reps));
    for(int i=1, j=1, comp=0; i<=N; i++) {
        if(i<=3)
            nums[i] = i;
        else
            nums[i] = (nums[i-1] + nums[i-2] + nums[i-3])%M + 1;
        reps[nums[i]]++;
        if(nums[i]>K)
            continue;
        if(reps[nums[i]]==1)
            comp ++;
        while(nums[j]>K || reps[nums[j]]>1) {
            reps[nums[j]]--;
            j++;
        }
        if(comp==K)
            ans = min(ans, i-j+1);
    }

    if(ans==MAX_N)
        printf("sequence nai\n");
    else
        printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
