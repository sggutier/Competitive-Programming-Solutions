#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef pair<par, int> pc;
#define f first
#define s second

int main() {
    int N;
    par kng;
    vector <pc> igs[4];

    scanf("%d", &N);
    scanf("%d %d", &kng.f, &kng.s);
    while(N--) {
        par pos;
        char tip;
        scanf("\n%c %d %d", &tip, &pos.f, &pos.s);
        if(pos.f == kng.f)
            igs[0].push_back({pos, tip!='B'});
        if(pos.s == kng.s)
            igs[1].push_back({pos, tip!='B'});
        if(pos.f + pos.s == kng.f + kng.s)
            igs[2].push_back({pos, tip!='R'});
        if(pos.f - pos.s == kng.f - kng.s)
            igs[3].push_back({pos, tip!='R'});
    }

    for(int i=0; i<4; i++) {
        if(igs[i].empty())
            continue;
        sort(igs[i].begin(), igs[i].end());
        int p = lower_bound(igs[i].begin(), igs[i].end(), pc(kng, 1)) - igs[i].begin();
        if(p < (int) igs[i].size()) {
            if(igs[i][p].s) {
                printf("YES\n");
                return 0;
            }
        }
        if(p > 0) {            
            p--;
            if(igs[i][p].s) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
}
