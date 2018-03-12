#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int inf = 1e9 ;
const int uD = 150000;

struct STree {
    vector <int> vals;
    int n ;
    STree() {
        n = 0;
    }    
    STree(const vector <int> &nums) {
        n = nums.size();
        vals = vector<int>(2*n);
        vals.resize(2*n);
        for(int i=0; i<n; i++)
            vals[i+n] = nums[i];
        for(int i=n-1; i>0; i--)
            vals[i] = min(vals[i<<1], vals[(i<<1)|1]);
    }
    int __get(int l, int r) {
        int ans = inf;
        for(l += n, r += n; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, vals[l++]);
            if(r & 1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
    int get(int l, int r) {
        return __get(min(l, r), max(l, r)+1);
    }
};

void buscaHs(int N, const vector <int> &nums, STree &st, int *ans, int dir) {
    int mays[limN], poss[limN];
    int W = 2;
    mays[0] = -inf;
    mays[1] = 0;
    mays[2] = 0;
    poss[0] = dir==1? -1 : N;
    poss[1] = poss[0] + dir;
    //printf("%d == \n", dir);
    for(int i=(N+dir*2)%(N+1); i>=0 && i<N; i+=dir) {
        W = lower_bound(mays, mays+W+1, -nums[i]) - mays;
        // printf("[%d] ", nums[i]);
        // for(int i=0; i<=W; i++)
        //     printf("(%d %d) ", mays[i], poss[i]);
        ans[i] = st.get(i, poss[W-1]+dir);
        // printf(" ==> %d %d", nums[poss[W-1]+dir], st.get(i, poss[W-1]+dir));
        // printf("\n");
        mays[W] = -nums[i];
        poss[W] = i;
        mays[++W] = 0;
    }
}

void testCase(int N) {
    STree st;
    vector <int> nums(N);
    int minHL[N], minHR[N];
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    st = STree(nums);
    
    buscaHs(N, nums, st, minHL, 1);
    buscaHs(N, nums, st, minHR, -1);

    int ansCnt = 0;
    for(int i=0; i<N; i++) {
        if(nums[i] < uD)
            continue;
        int w = max(minHL[i], minHR[i]) ;
        if(nums[i] - w >= uD) {
            if(ansCnt++)
                printf(" ");
            printf("%d", i+1);
        }
    }
    printf("\n");
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
