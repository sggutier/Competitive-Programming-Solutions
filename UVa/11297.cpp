#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);

//template <class T>
class SegmentTree {
private:
    vector<int> st;
    int n;
public:
    SegmentTree() {
    }
    SegmentTree(int _n) {
        st = vector<int>(2*_n, -inf);
        n = _n;
    }
    SegmentTree(const vector <int> &_v) {
        int n = _v.size();
        st = vector<int> (2*n);
        for(int i=0; i<n; i++)
            st[i+n] = _v[i];
        for(int i=n-1; i>0; i--)
            st[i] = max(st[i<<1], st[(i<<1)|1]);
    }
    int rmq(int l, int r) {
        int ans = -inf;
        // printf("starting rmq with %d %d\n", l+n, r+n);
        for(l+=n, r+=n; l < r; l >>= 1, r >>= 1) {
            if(l&1) {
                // printf("lhiar -> %d >>> %d\n", l, st[l]);
                ans = max(ans, st[l++]);
            }
            if(r&1) {
                // printf("rhiar -> %d >>> %d\n", r, st[r-1]);
                ans = max(ans, st[--r]);
            }
        }
        // printf("answed %d\n", ans);
        return ans;
    }
    void update(int pos, int nov) {
        pos += n;
        // printf("updating col %d and val %d\n", pos, nov);
        st[pos] = nov;
        pos >>= 1;
        while(pos>0) {
            // printf("updating col (new) %d and val %d\n", pos, max(st[pos<<1], st[(pos<<1)|1]));
            st[pos] = max(st[pos<<1], st[(pos<<1)|1]);
            pos >>= 1;
        }
    }
};

class SegmentTree2D {
private:
    vector<SegmentTree> st;
    int n ;
public:
    SegmentTree2D() {
    }
    SegmentTree2D(const int &rows, const int &cols) {
        st = vector<SegmentTree> (2*rows, SegmentTree(cols));
        n = rows;
    }
    int rmq(int u, int d, int l, int r) {
        int ans = -inf;
        // printf("queriestart with %d %d\n", u+n, d+n);
        for(u+=n, d+=n; u < d; u >>= 1, d >>= 1) {
            if(u&1) { // printf("Querying row (up) %d from %d to %d\n", u, l, r);
                ans = max(ans, st[u++].rmq(l, r)); }
            if(d&1) {
                // printf("Querying row (down) %d from %d to %d\n", d-1, l, r);
                ans = max(ans, st[--d].rmq(l, r)); }
        }
        return ans;
    }
    void update(int row, int col, int nov) {
        row += n;
        // printf("updating row %d with col %d and val %d\n", row, col, nov);
        // novo("before: ");        
        st[row].update(col, nov);
        row >>= 1;
        while(row>0) {
            // break;
            // printf("updating row %d with col %d and val %d\n", row, col, nov);
            nov = max(st[row<<1].rmq(col, col+1),
                      st[(row<<1)|1].rmq(col, col+1));
            st[row].update(col, nov);
            row >>= 1;
        }
    }
};

int main() {
    SegmentTree2D stMax, stMin;
    int n, q ;

    scanf("%d", &n);
    stMax = SegmentTree2D(n, n);
    stMin = SegmentTree2D(n, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int tmp;
            scanf("%d", &tmp);
            // if(i<2)
            stMax.update(i, j, tmp);
            stMin.update(i, j, -tmp);
        }
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        char qtype ;
        scanf("\n%c", &qtype);
        switch(qtype) {
        case 'q':
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            // printf("%d %d %d %d\n", x1, y1, x2, y2);
            printf("%d ", stMax.rmq(x1-1, x2, y1-1, y2));
            printf("%d\n", -stMin.rmq(x1-1, x2, y1-1, y2));
            break;
        case 'c':
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            // printf("%d %d %d\n", x, y, v);
            stMax.update(x-1, y-1, v);
            stMin.update(x-1, y-1, -v);
            break;
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         // printf("QUERIED %d %d with %d\n", i, j, stMax.rmq(i, i+1, j, j+1));
    //         printf("%d ", stMax.rmq(i, i+1, j, j+1));
    //     }
    //     printf("\n");
    // }
  
    return 0;
}
