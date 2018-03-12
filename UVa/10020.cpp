#include <bits/stdc++.h>
using namespace std;
const int limN = 100001;
const int inf = (1<<30);
#define par pair<int,int>
#define f first
#define s second

int numCnt = 0;
par nums[limN];

void testCase() {
    int M;
    scanf("%d", &M);
    numCnt = 1;
    while(scanf("%d%d", &nums[numCnt].f, &nums[numCnt].s)!=EOF && (nums[numCnt].f || nums[numCnt].s))
        numCnt ++;
    numCnt --;

    sort(nums+1, nums+1+numCnt);

    list <int> ans;
    int ult=0, pos=1;
    while(ult<M) {
        int sig = pos;
        while(pos<=numCnt && nums[pos].f <= ult) {
            if(nums[pos].s > nums[sig].s)
                sig = pos;
            pos ++;
        }
        if(nums[sig].f > ult || nums[sig].s <= ult) {
            printf("0\n");
            return;
        }
        ult = nums[sig].s;
        ans.push_back(sig);
    }
    
    printf("%d\n", (int) ans.size());
    for(const int &pos:ans) {
        printf("%d %d\n", nums[pos].f, nums[pos].s);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);

    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
