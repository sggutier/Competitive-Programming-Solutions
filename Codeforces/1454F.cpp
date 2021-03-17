#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct Tree {
    typedef int T;
    const T LOW = -1234567890;
    T f(T a, T b) { return max(a, b); }

    int n;
    vector<int> s;
    Tree() {}
    Tree(int m, T def=0) { init(m, def); }
    void init(int m, T def) {
        n = 1; while (n < m) n *= 2;
        s.assign(n + m, def);
        s.resize(2 * n, LOW);
        for (int i = n; i --> 1; )
            s[i] = f(s[i * 2], s[i*2 + 1]);
    }
    void update(int pos, T val) {
        pos += n;
        s[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int l, int r) { return que(1, l, r, 0, n); }
    T que(int pos, int l, int r, int lo, int hi) {
        if (r <= lo || hi <= l) return LOW;
        if (l <= lo && hi <= r) return s[pos];
        int m = (lo + hi) / 2;
        return f(que(2 * pos, l, r, lo, m),
                que(2 * pos + 1, l, r, m, hi));
    }
};

pii findMx(Tree &maxs, int orgFin, int x) {
    int ini = 0, fin = orgFin - 1;
    pii ans = {-1, -1};
    while(ini < fin) {
        int piv = (ini + fin) / 2;
        if(maxs.query(0, piv+1) < x)
            ini = piv + 1;
        else
            fin = piv;
    }
    if(maxs.query(ini, ini+1) != x) {
        return ans;
    }
    ans.first = ini;
    fin = orgFin - 1;
    while(ini < fin) {
        int piv = (ini + fin) / 2 + 1;
        if(maxs.query(0, piv+1) <= x)
            ini = piv;
        else
            fin = piv - 1;
    }
    ans.second = ini;
    return ans;
}

pii findMn(Tree &mins, int orgFin, int x) {
    int ini = 1, fin = orgFin;
    pii ans = {-1, -1};
    while(ini < fin) {
        int piv = (ini + fin) / 2;
        if(-mins.query(piv, orgFin+1) < x)
            ini = piv + 1;
        else
            fin = piv;
    }
    if(-mins.query(ini, orgFin+1) != x) {
        return ans;
    }
    ans.first = ini;
    fin = orgFin ;
    while(ini < fin) {
        int piv = (ini + fin) / 2 + 1;
        if(-mins.query(piv, orgFin+1) <= x)
            ini = piv;
        else
            fin = piv - 1;
    }
    ans.second = ini;
    return ans;
}

void testCase(int N, vector <int> &nums) {
    Tree mins(N), maxs(N);
    for(int i=0; i < N; i++) {
        mins.update(i, -nums[i]);
        maxs.update(i, nums[i]);
    }
    for(int i=N-1, acm=nums[N-1]; i > 1; i--) {
        acm = max(acm, nums[i]);
        pii x = findMx(maxs, i-1, acm);
        pii y = findMn(mins, i-1, acm);
        // printf("%d (%d) => %d %d | %d %d\n", i+1, acm, x.first+1, x.second+1, y.first+1, y.second+1);
        int a = max(x.first, y.first - 1);
        int b = min(x.second, y.second - 1);
        if(b < 0 || b < a) continue;
        printf("YES\n");
        printf("%d %d %d\n", a+1, i-(a+1), N-i);
        return ;
    }
    printf("NO\n");
}

int main() {
    int T ;
    scanf("%d", &T);
    for(int i=0, N; i < T; i++) {
        scanf("%d", &N);
        vector<int> nums(N);
        for(int j=0; j < N; j++) {
            scanf("%d", &nums[j]);
        }
        testCase(N, nums);
    }
}
