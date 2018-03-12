#include <bits/stdc++.h>
using namespace std;

inline int interLen(int a, int b, int x, int y) {
    return min(y,b) - max(a,x) + 1;
}

class SegmTree {
private:
    int n;
    vector <int> vals;
    int _get(int l, int r) {
        int ans = 0;
        l += n, r += n;
        for(; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = max(ans, vals[l++]);
            if(r & 1)
                ans = max(ans, vals[--r]);
        }
        return ans;
    }
public:
    SegmTree(vector <int> &cpy) {
        n = cpy.size();
        vals.resize(2*n);
        for(int i=0; i<n; i++) {
            vals[i+n] = cpy[i];
        }
        for(int i=n-1; i>0; i--) {
            vals[i] = max(vals[i<<1], vals[(i<<1)|1]);
        }
    }
    int get(int a, int b) {
        return this -> _get(a, b+1);
    }
};

void testCase(int numCnt) {
    int querCnt;
    vector <int> nums(numCnt), leftPos(numCnt), rightPos(numCnt), rngID(numCnt);
    vector <int> freqs;

    scanf("%d", &querCnt);
    for(int i=0; i<numCnt; i++) {
        scanf("%d", &nums[i]);
        if(i && nums[i]==nums[i-1])
            freqs[freqs.size()-1]++;
        else
            freqs.push_back(1);
        rngID[i] = freqs.size()-1;
    }
    for(int i=0; i<numCnt; i++) {
        if(i && nums[i]==nums[i-1])
            leftPos[i] = leftPos[i-1];
        else
            leftPos[i] = i;
        if(i && nums[numCnt-i-1]==nums[numCnt-i])
            rightPos[numCnt-i-1] = rightPos[numCnt-i];
        else
            rightPos[numCnt-i-1] = numCnt-i-1;
    }
    if(numCnt==0) {
        printf("0\n");
        return ;
    }

    SegmTree st(freqs);
    while(querCnt--) {
        int a, b, ans;
        scanf("%d%d", &a, &b);
        a--, b--;
        ans = max(interLen(a, b, leftPos[a], rightPos[a]), interLen(a, b, leftPos[b], rightPos[b]));
        if(rngID[a] + 1 <= rngID[b] - 1) {
            ans = max(ans, st.get(rngID[a]+1, rngID[b]-1));
        }
        printf("%d\n", ans);
    }
}

int main() {
    int a;

    while(scanf("%d", &a)!=EOF && a)
        testCase(a);
    
    return 0;
}
