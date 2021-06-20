#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

class segmTree {
private:
    int n;
    vector <int> vals;
    void _update(int pos, int val) {
        pos += n;
        vals[pos] = val;
        // pos >>= 1;
        pos /= 2;
        while(pos>0) {
            vals[pos] = vals[pos<<1] * vals[pos<<1|1];
            // pos >>= 1;
            pos /= 2;
        }
    }
    int _get(int l, int r) {        
        int ans = 1;
        for(l += n, r += n; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans *= vals[l++];
            if(r & 1)
                ans *= vals[--r];
        }
        return ans;
    }
public:
    segmTree() {
    }
    segmTree(int _n) {
        n = _n;
        vals = vector<int>(2*n, 1);
    }
    segmTree(const vector<int> &arr) {
        n = arr.size();
        vals = vector<int>(2*n);
        for(int i=0; i<n; i++)
            vals[i+n] = arr[i]>0? 1 : (arr[i]==0? 0 : -1);
        for(int i=n-1; i>0; i--)
            vals[i] = vals[i<<1] * vals[i<<1|1];
    }
    void update(int num, long long val) {
        _update(num, val);
    }
    int get(int minRan, int maxRan) {
        return _get(minRan, maxRan);
    }
};

void testCase(int N, int Q) {
    vector<int> nums(N);

    for(auto &n:nums)
        scanf("%d", &n);
    segmTree st(nums);   

    for(; Q; Q--) {
        int a, b;
        char S[5];
        scanf("%s%d%d", S, &a, &b);
        a--;
        if(S[0]=='C') {
            if(b)
                b = b/abs(b);
            st.update(a, b);
        }
        else {
            int tmp = st.get(a, b);
            // printf("%d\n", tmp);
            printf("%c", tmp>0? '+' : (tmp==0? '0' : '-'));
        }
    }
    
    printf("\n");
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF) {
        testCase(a, b);
    }
    
    return 0;
}
