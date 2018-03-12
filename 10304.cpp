#include <bits/stdc++.h>
using namespace std;
const int limN = 255;

int sums[limN][limN];
int minTot[limN][limN];

void testCase(int numCnt) {
    int nums[limN];

    // scanf("%d", &numCnt);
    for(int i=1; i<=numCnt; i++) {
        scanf("%d", &nums[i]);
        for(int j=i, k=0; j; j--) {
            k += nums[j];
            sums[j][i] = k;
        }
    }
    // cout << "hiar? " << endl;

    for(int dst=0; dst<numCnt; dst++) {
        for(int ini=numCnt-dst; ini; ini--) {
            int fin = ini+dst;
            int ans = (1<<30);
            for(int k=ini; k<=fin; k++) {
                ans = min(ans, sums[ini][k-1] + sums[k+1][fin] + minTot[ini][k-1] + minTot[k+1][fin]);
            }
            minTot[ini][fin] = ans;
        }
    }

    printf("%d\n", minTot[1][numCnt]);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
