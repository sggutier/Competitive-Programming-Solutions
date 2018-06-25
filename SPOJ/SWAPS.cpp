#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
const int limN = 3e5 + 5;
const int H = 50000;

ordered_set ords[H*2 + 5];

void mete(int x, int y) {
    for(y += H; y; y>>=1)
        ords[y].insert(x);
}

void saca(int x, int y) {
    for(y += H; y; y>>=1)
        ords[y].erase(x);
}

int cuenta(int xl, int xr, int yl, int yr) {
    if(xr < xl || yr < yl)
        return 0;
    int ans = 0;
    for(yl += H, yr += H+1; yl<yr; yl>>=1, yr>>=1) {
        if(yl & 1) {
            ans += ords[yl].order_of_key(xr+1) - ords[yl].order_of_key(xl) ;
            yl ++;
        }
        if(yr & 1) {
            yr --;
            ans += ords[yr].order_of_key(xr+1) - ords[yr].order_of_key(xl) ;
        }
    }
    return ans;
}

int main() {
    int N ;
    int arr[limN];
    int Q ;
    ll ans = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        mete(i, arr[i]);
        ans += cuenta(1, i-1, arr[i]+1, H);
    }

    for(scanf("%d", &Q); Q; Q--) {
        int x, y, z;
        scanf("%d%d", &x, &y);
        z = y;
        
        y = arr[x];
        ans -= cuenta(1, x-1, y+1, H);
        ans -= cuenta(x+1, N, 1, y-1);
        saca(x, y);
        
        y = z;
        arr[x] = z;
        mete(x, y);
        ans += cuenta(1, x-1, y+1, H);
        ans += cuenta(x+1, N, 1, y-1);
        
        printf("%lld\n", ans);
    }
}
