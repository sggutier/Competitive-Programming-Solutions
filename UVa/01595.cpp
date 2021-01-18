#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
const int LIM_N = 1005;

pii pts[LIM_N];

void testCase()  {
    int N ;
    int minV = 1e9, maxV = -1e9 ;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        pts[i].x *= 2 ;
        minV = min(minV, pts[i].x);
        maxV = max(maxV, pts[i].x);
    }

    for(int m=0; m < N; m++) {
        int x = pts[m].x;
        set <pii> st ;
        for(int i=0; i < N; i++) {
            if(pts[i].x == x) continue ;
            pii mit = {abs(pts[i].x - x), pts[i].y};
            auto it = st.find(mit);
            if(it != st.end())
                st.erase(it);
            else
                st.insert(mit);
        }
        if(st.empty()) {
            printf("YES\n");
            return ;
        }
    }
    int x = (minV + maxV) / 2 ;
    set <pii> st ;
    for(int i=0; i < N; i++) {
        if(pts[i].x == x) continue ;
        pii mit = {abs(pts[i].x - x), pts[i].y};
        auto it = st.find(mit);
        if(it != st.end())
            st.erase(it);
        else
            st.insert(mit);
    }
    if(st.empty()) {
        printf("YES\n");
        return ;
    }
    printf("NO\n");
}

int main() {
    freopen("01595.in", "r", stdin);
    int TC ;
    for(scanf("%d", &TC); TC; TC--)
        testCase();
}
