#include <bits/stdc++.h>
using namespace std ;
#define lim 5005

int crg[lim];

void mete(int nov, int pos) {
    for(; pos<lim; pos += (pos & -pos))
        crg[pos] += nov;
}

int saca(int pos) {
    int ans = 0;
    for(; pos; pos -= (pos & -pos))
        ans += crg[pos];
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    scanf("%d", &t);
    while(t--)  {
        memset(crg, 0, sizeof(crg));
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            int tmp;
            scanf("%d", &tmp);
            ans += saca(tmp);
            mete(1, tmp);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
