#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;

int nums[LIM_N];
int ords[LIM_N];

void testCase(int N) {
    set <int> ans;
    for(int i=0; i < N; i++) {
        scanf("%d", &nums[i]);
        ords[i] = i;
    }
    sort(ords, ords+N,
         [](const int a, const int b) {
             return nums[a] < nums[b];
         });
    int minP = 0;
    long long sm = 0 ;
    for(int k=0; k < N; k++) {
        int pos = ords[k];
        if(sm < nums[pos])
            minP = k;
        sm += nums[pos];
    }
    for(int i=minP; i < N; i++)
        ans.insert(ords[i]);
    printf("%d\n", (int) ans.size());
    for(const int x : ans)
        printf("%d ", x + 1);
    printf("\n");
}

int main() {
    int tc;
    int N ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &N);
        testCase(N);
    }
}
