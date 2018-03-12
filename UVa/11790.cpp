#include <bits/stdc++.h>
using namespace std;

int numCnt;
vector <int> heights, widths;
vector <int> maxW;

int LIS() {
    int ans = 0;
    for(int i=0; i<numCnt; i++) {
        int tmp = 0;
        for(int j=0; j<i; j++) {
            if(heights[j] < heights[i])
                tmp = max(tmp, maxW[j]);
        }
        maxW[i] = tmp + widths[i];
        ans = max(ans, maxW[i]);
    }
    return ans;
}

void testCase() {
    scanf("%d", &numCnt);
    heights.resize(numCnt);
    widths.resize(numCnt);
    maxW.resize(numCnt);
    for(int i=0; i<numCnt; i++) {
        scanf("%d", &heights[i]);
    }
    for(int i=0; i<numCnt; i++) {
        scanf("%d", &widths[i]);
    }
    int x = LIS();
    for(int i=0; i<numCnt; i++)
        heights[i] *= -1;
    int y = LIS();
    if(x>=y)
        printf("Increasing (%d). Decreasing (%d).\n", x, y);
    else
        printf("Decreasing (%d). Increasing (%d).\n", y, x);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d. ", i);
        testCase();
    }
    
    return 0;
}
