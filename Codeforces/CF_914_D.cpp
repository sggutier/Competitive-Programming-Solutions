#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;

class SegmTree {
private:
    int n;
    vector <int> vals;
    int _get(int l, int r) {
        int ans = 0;
        l += n, r += n;
        for(; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = __gcd(ans, vals[l++]);
            if(r & 1)
                ans = __gcd(ans, vals[--r]);
        }
        return ans;
    }
public:
    void inita(vector <int> &cpy) {
        n = cpy.size();
        vals.resize(2*n);
        for(int i=0; i<n; i++) {
            vals[i+n] = cpy[i];
        }
        for(int i=n-1; i>0; i--) {
            vals[i] = __gcd(vals[i<<1], vals[(i<<1)|1]);
        }
    }
    void upd(int a, int p) {
        a += n;
        vals[a] = p;
        for(int i = a>>1; i; i>>=1) {
            vals[i] = __gcd(vals[i<<1], vals[(i<<1)|1]);
        }
    }
    int get(int a, int b) {
        if(a  > b)
            return 0;
        return this -> _get(a, b+1);
    }
};

vector <int> nums;
SegmTree st;

bool query(int a, int b, int x) {
    if(st.get(a, b)%x == 0)
        return true;
    int n, m ;
    int ini, fin, piv;
    ini = a, fin = b;
    while(ini < fin) {
        piv = (ini+fin)/2 ;
        if(st.get(ini, piv) %x )
            fin = piv;
        else
            ini = piv + 1;
    }
    n = ini;
    return st.get(n+1, b) % x == 0;
}

int main() {
    int N, Q ;

    scanf("%d", &N);
    nums.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    st.inita(nums);

    scanf("%d", &Q);
    while(Q--) {
        int t, a, b, c;
        scanf("%d", &t);
        if(t==1) {
            scanf("%d%d%d", &a, &b, &c);
            printf("%s\n", query(a-1, b-1, c)? "YES" : "NO");
        }
        else {
            scanf("%d%d", &a, &b);
            st.upd(a-1, b);
        }
    }
}
