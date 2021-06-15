#include <bits/stdc++.h>
using namespace std;
const int limK = 1000;

void testCase(int wyardCnt) {
    vector <vector<char>> posb(wyardCnt+1, vector<char>(limK+1));
    int nums[55];
    int maxProf = 0;
    
    nums[0] = 0;
    posb[0][0] = 1;

    for(int w=1; w<=wyardCnt; w++) {
        int K, maxSum = 0;
        scanf("%d", &K);
        for(int i=1, sum=0; i<=K; i++) {
            scanf("%d", &nums[i]);
            nums[i] = 10 - nums[i];
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        for(int i=0, sum=0; i<=K; i++) {
            sum += nums[i];
            if(sum==maxSum) {
                for(int s=i; s<=limK; s++) {
                    posb[w][s] |= posb[w-1][s-i];
                }
            }
        }
        maxProf += maxSum;
    }

    printf("Maximum profit is %d.\n", maxProf);
    printf("Number of pruls to buy:");
    for(int i=0, aCnt=0; i<=limK; i++) {
        if(posb[wyardCnt][i]) {
            printf(" %d", i);
            if((++aCnt)==10)
                break;
        }
    }
    printf("\n");
}

int main() {
    int tc = 0;
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        if(tc++)
            printf("\n");
        printf("Workyards %d\n", tc);
        testCase(n);
    }
    
    return 0;
}
