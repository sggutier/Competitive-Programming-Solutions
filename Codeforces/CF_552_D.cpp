#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;
typedef pair<int,int> par;
#define x first
#define y second

int N ;
par pts[limN];

int main() {
    long long ans = 0;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        map <par, int> tots;
        scanf("%d%d", &pts[i].x, &pts[i].y);
        for(int j=0; j<i; j++) {
            par w = {pts[i].x - pts[j].x, pts[i].y - pts[j].y};
            // printf("%d %d\n", w.x, w.y);
            int k = __gcd(abs(w.x), abs(w.y));
            if(w.x < 0 || (w.x==0 && w.y < 0)) 
                w.x *= -1, w.y *= -1;
            w.x /= k, w.y /= k;
            tots[w]++;
        }
        for(auto &t : tots) {
            ans += t.second * (i - t.second);
            // printf("%d %d => %d %d\n", t.x.x, t.x.y, i, t.second);
        }
    }

    printf("%lld\n", ans/2);
}
