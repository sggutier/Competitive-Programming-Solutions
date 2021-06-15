#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e6 ;

int mex[LIM_N];
int repCnt[LIM_N];
int sqrts[LIM_N];

int getVal(const ll i, int &lstA, int &lstB) {
    ll b = sqrtl(i);
    ll a = sqrtl(b)-1;
    while(a*a*a*a < i && a < i)
        a ++;
    if(b < a || b == i){
        return 0;
    }
    for(; lstB < b; lstB ++) {
        // printf("+ %d %d\n", lstB + 1, mex[lstB + 1]);
        repCnt[mex[lstB + 1]] ++;
    }
    for(; lstA < a; lstA ++) {
        // printf("- %d %d\n", lstA, mex[lstA]);
        repCnt[mex[lstA]] --;
    }
    // printf("\t%d %d\n", lstA, lstB);
    // printf("\t");
    // for(int j=0; j < 10; j++)
    //     printf("%d ", repCnt[j]);
    // printf("\n");
    int v = 0;
    for(v=0; ; v ++) {
        if(repCnt[v] == 0)
            break;
    }
    return v ;
}

void init() {
    int N = LIM_N;
    int lstA = 1, lstB = 1;
    repCnt[0] ++;
    for(int i=2; i < N; i++) {
        mex[i] = getVal(i, lstA, lstB);
        // printf(">>>>>> %d => %d\n", i, mex[i]);
    }
    memset(repCnt, 0, sizeof(repCnt));
}

ll nums[LIM_N];

int main() {
    init();
    int N ;
    int ans = 0 ;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%lld", &nums[i]);
    }
    sort(nums, nums+N);

    repCnt[0] ++;
    int lstA = 1, lstB = 1;
    for(int k=0; k < N; k++) {
        if(nums[k] == 1)
            continue;
        int v = getVal(nums[k], lstA, lstB);
        // printf("%d => %d\n", nums[k], v);
        ans ^= v;
    }
    printf("%s\n", ans? "Furlo" : "Rublo");
}
