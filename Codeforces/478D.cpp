#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll mod = 1e9 + 7;
const ll inf = (1<<30);
const int limH = 1005;
const int limN = 4e5 + 5;

ll ways[limN];
bool posb[limN];

int main() {
    int R, G, T;
    ll ans = 0;
    int maxS = 0, maxH = 0;
    
    scanf("%d%d", &R, &G);
    T = R+G;
    
    ways[0] = 1;
    posb[0] = true;

    for(int i=1, sumo=1; sumo <= T; i++) {
        if(R + G < sumo)
            break;
        maxS = sumo;
        maxH = i;
        sumo += i+1;
    }
    
    for(int i=1; i <= maxH; i++) {
        for(int j=maxS; j>=i; j--) {
            if(!posb[j-i])
                continue;
            posb[j] = true;
            ways[j] = (ways[j] + ways[j-i]) % mod;
        }
    }

    for(int i=0; i<=R; i++) {
        if(i+G >= maxS)
            ans = (ans + ways[i]) % mod;
    }

    printf("%d\n", ans);
}
