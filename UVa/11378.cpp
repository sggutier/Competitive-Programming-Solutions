#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define x first
#define y second
const int limN = 1e5 + 5;

int dst(const par A, const par B) {
    return max(abs(A.x-B.x), abs(A.y-B.y));
}

void testCase(int N) {
    par pts[limN];
    int ans = 1e9 + 5;
    set <par> cands;

    for(int i=0; i<N; i++)
        scanf("%d%d", &pts[i].x, &pts[i].y);
    if( N <= 1) {
        printf("0\n");
        return;
    }

    sort(pts, pts+N, [] (par A, par B) { return A.y != B.y? A.y < B.y : A.x < B.y; });

    for(int i=0, j=0; i<N; i++) {
        while(pts[i].y - pts[j].y > ans)
            cands.erase(pts[j++]);
        auto p = cands.lower_bound(pts[i]);
        for(auto it=p; it!=cands.end() && abs(it->x - pts[i].x) <= ans; it++)
            ans = min(ans, dst(*it, pts[i]));
        for(auto it=p; it!=cands.begin(); ) {
            it --;
            if(abs(it->x - pts[i].x) > ans)
                break;
            ans = min(ans, dst(*it, pts[i]));
        }
        p = cands.begin();
        if(p != cands.end())
            ans = min(ans, dst(*p, pts[i]));
        cands.insert(pts[i]);
    }

    printf("%d\n", ans);
}

int main() {
    int n ;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
