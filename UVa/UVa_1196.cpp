#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int limN = 1e4 + 5;

void testCase(int numCnt) {
    static par nums[limN];
    static int minH[limN];
    int H = 1;
    minH[0] = 0;
    for(int i=0; i<numCnt; i++) {
        scanf("%d%d", &nums[i].f, &nums[i].s);
    }
    sort(nums, nums+numCnt);
    for(int i=0; i<numCnt; i++) {
        int pos = upper_bound(minH, minH+H, nums[i].s) - minH ;
        if(pos==H)
            H++;
        minH[pos] = nums[i].s;
    }
    printf("%d\n", H-1);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    printf("*\n");
}
