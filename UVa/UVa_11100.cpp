#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int N;
int nums[limN];
vector <int> ros[limN];

void testCase() {
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        ros[i].clear();
    }
    sort(nums, nums+N);

    int ans = 0;
    nums[N] = 0;
    for(int i=N-1; i>=0; ) {
        int j;
        for(j=i; j>=0 && nums[j]==nums[i]; j--) ;
        ans = max(ans, i-j);
        i = j;
    }

    for(int i=N-1, w=0; i>=0; ) {
        int j;
        for(j=i; j>=0 && nums[j]==nums[i]; j--) {
            ros[w].push_back(nums[j]);
            w = (w+1)%ans;
        }
        i = j;
    }

    printf("%d\n", ans);
    for(int i=0; i<ans; i++) {
        printf("%d", ros[i][ros[i].size()-1]);
        for(int j=ros[i].size()-2; j>=0; j--)
            printf(" %d", ros[i][j]);
        printf("\n");
    }
}

int main() {
    int tc=0;
    while(scanf("%d", &N)!=EOF && N) {
        if(tc++)
            printf("\n");
        testCase();
    }
}
