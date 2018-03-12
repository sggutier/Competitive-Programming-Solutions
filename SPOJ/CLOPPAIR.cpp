#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define x first
#define y second
#define w first
#define z second
const int limN = 5e4 + 5;
typedef pair<par, int> tri;

double dst(const tri A, const tri B) {
    double a = A.w.x - B.w.x, b = A.w.y - B.w.y;
    return sqrt(a*a + b*b);
}

void testCase(int N) {
    tri pts[limN];
    pair<double, par> ans = {1e9, {0, 0}};
    set <tri> cands;

    for(int i=0; i<N; i++) {
        scanf("%d%d", &pts[i].w.x, &pts[i].w.y);
        pts[i].z = i;
    }
    if( N <= 1) {
        printf("INFINITY\n");
        return;
    }

    sort(pts, pts+N, [] (tri A, tri B) { return A.w.y != B.w.y? A.w.y < B.w.y : A.w.x < B.w.y; });

    for(int i=0, j=0; i<N; i++) {
        while(pts[i].w.y - pts[j].w.y > ans.w)
            cands.erase(pts[j++]);
        auto p = cands.lower_bound(pts[i]);
        for(auto it=p; it!=cands.end() && abs(it->w.x - pts[i].w.x) <= ans.w; it++)
            ans = min(ans, {dst(*it, pts[i]), {it->z, pts[i].z}});
        for(auto it=p; it!=cands.begin(); ) {
            it --;
            if(abs(it->w.x - pts[i].w.x) > ans.w)
                break;
            ans = min(ans, {dst(*it, pts[i]), {it->z, pts[i].z}});
        }
        p = cands.begin();
        if(p != cands.end())
            ans = min(ans, {dst(*p, pts[i]), {p->z, pts[i].z}});
        cands.insert(pts[i]);
    }

    if(ans.z.x > ans.z.y)
        swap(ans.z.x, ans.z.y);
    printf("%d %d %.6lf\n", ans.z.x, ans.z.y, ans.first);
}

int main() {
    int n ;

    //while(scanf("%d", &n)!=EOF && n)
    scanf("%d", &n);
    testCase(n);
}
