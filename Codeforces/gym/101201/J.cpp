#include <bits/stdc++.h>
using namespace std;
const long long inf = (1LL<<60);
const int limN = 2e5 + 5;

class segmTree {
private:    
    int n;
    // vector <long long> vals;
    long long vals[limN*2];
    void _update(int pos, long long val) {
        pos += n;
        vals[pos] = val;
        pos /= 2;
        while(pos>0) {
            vals[pos] = min(vals[pos<<1], vals[pos<<1|1]);
            pos /= 2;
        }
    }
    long long _get(int l, int r) {
        l += n;
        r += n;
        long long ans = inf;
        for(; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, vals[l++]);
            if(r & 1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
public:
    segmTree() {
    }
    segmTree(int _n) {
        n = _n;
        // vals = vector<long long>(n, inf);
        for(int i=2*n-1; i; i--)
            vals[i] = inf;
    }
    segmTree(int _n, long long *arr) {
        n = _n;
        for(int i=0; i<n; i++)
            vals[i+n] = arr[i];
        for(int i=n-1; i>0; i--) {
            vals[i] = min(vals[i<<1], vals[i<<1|1]);
            // vals[i] = min(vals[i]
        }
    }
    void update(int num, long long val) {
        _update(num, val);
    }
    long long get(int minRan, int maxRan) {
        return _get(minRan, maxRan+1);
    }
};

long long query(long long mon, int left, int right, long long *items, segmTree &st) {
    int pos = left;
    while(pos<=right) {
        // cout << pos << " " << mon << endl;
        mon %= items[pos];
        if(pos==right) {
            break;
        }
        pos ++;
        int ini=pos, fin=right;
        while(ini<fin) {
            int piv = (ini+fin)/2;
            if(st.get(pos, piv)<=mon)
                fin = piv;
            else
                ini = piv+1;
        }
        pos = ini;
    }
    return mon;
}

segmTree st;

int main() {
    ios_base::sync_with_stdio(0);
    int itemCnt, buyCnt;
    long long items[limN];
    // vector <long long> items;

    // scanf("%d%d", &itemCnt, &buyCnt);
    cin >> itemCnt >> buyCnt;
    // st = segmTree(itemCnt);
    for(int i=0; i<itemCnt; i++) {
        // scanf("%l64d", &items[i]);
        cin >> items[i];
        // st.update(i, items[i]);
    }
    st = segmTree(itemCnt, items);
    for(int i=0; i<buyCnt; i++) {
        long long mon;
        int a, b;
        // scanf("%l64d%d%d", &mon, &a, &b);
        cin >> mon >> a >> b;
        // printf("%l64d\n", query(mon, a-1, b-1, items, st));
        cout << query(mon, a-1, b-1, items, st) << '\n';
    }
  
    return 0;
}
