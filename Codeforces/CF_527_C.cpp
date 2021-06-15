#include <bits/stdc++.h>
using namespace std;

set <int> xs, ys;
set < tuple<int, int, int> > raxs, rays;

void corta(set <int> &ps, set < tuple<int, int, int> > &rgs, const int x) {
    auto w = ps.insert(x).first;
    auto l = w, r = w;
    l --;
    r ++;
    rgs.erase({*l - *r, *l, *r});
    rgs.insert({*l - *w, *l, *w});
    rgs.insert({*w - *r, *w, *r});
}

long long maxL(set < tuple<int, int, int> > &rgs) {
    int ans ;
    tie(ans, ignore, ignore) = *rgs.begin();
    return ans;
}

int main() {
    int w, h, n;

    scanf("%d%d%d", &w, &h, &n);
    xs.insert(0);
    xs.insert(w);
    raxs.insert({-w, 0, w});
    ys.insert(0);
    ys.insert(h);
    rays.insert({-h, 0, h});

    char tmp[5];
    for(int i=0, x; i<n; i++) {
        scanf("%s%d", tmp, &x);
        if(tmp[0]=='V')
            corta(xs, raxs, x);
        else
            corta(ys, rays, x);
        printf("%lld\n", maxL(raxs) * maxL(rays));
    }
}
