#include <bits/stdc++.h>
using namespace std;
const int limN = 605;

int minP[limN][limN];
int nums[limN];

void testCase(int N, int K) {
    N++;
    K++;
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
        minP[i][0] = (1<<30);
    }
    for(int i=1; i<=N; i++) {
        for(int d=1; d<=K; d++) {
            int w = (1<<30), sum = nums[i];
            for(int j=i-1; j>=0; j--) {
                w = min(w, max(sum, minP[j][d-1]));
                sum += nums[j];
            }
            minP[i][d] = w;
            //printf("%d ", w);
        }
        //printf("\n");
    }
    printf("%d\n", minP[N][K]);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
}
