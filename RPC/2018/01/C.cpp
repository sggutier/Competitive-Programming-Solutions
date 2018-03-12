#include <bits/stdc++.h>
using namespace std;
const int limN = 21;
const int limB = 1<<limN;
const int inf = 1e9;
typedef pair<int,int> par;
#define f first
#define s second

int N ;
int vals[limN];
par dp[limB][2];
bool usd[limB][2];

void pmsk(int msk) {
    for(int i=0; i<N; i++)
        printf("%d", (1<<i) & msk? 1 : 0);
}

par memo(int msk, int prev) {
    if(msk==0)
        return {0,0};
    if(usd[msk][prev])
        return dp[msk][prev];
    usd[msk][prev] = true;
    par ans = {-1, 0};
    int rcnt = 0;

    for(int i=0; i<N; i++) {
        if(((1<<i) & msk)==0)
            continue;
        if(vals[i]==1)
            rcnt++;
    }

    for(int i=0; i<N; i++) {
        if(((1<<i) & msk)==0)
            continue;
        if(rcnt == 0 || prev != (vals[i]==1)) {
            par sig ;
            if(vals[i]==1 || (rcnt==0))
                sig = memo(msk-(1<<i), vals[i]==1);
            else
                sig = memo(msk, vals[i]==1);
            // ans = max(ans, {-sig.s + vals[i], -sig.f});
            ans = max(ans, {sig.f + vals[i], 0});
        }
    }

    if(ans.f==-1)
        ans.f = 0;

//    pmsk(msk);
//    printf(" %d => %d %d\n", prev, ans.f, -ans.s);
//    for(int i=0; i<N; i++) {
//        if(((1<<i) & msk)==0)
//            continue;
//        if(rcnt == 0 || prev != (vals[i]==1)) {
//            par sig ;
//            if(vals[i]==1 || (rcnt==0)) {
//                sig = memo(msk-(1<<i), vals[i]==1);
//                printf("\t");
//                pmsk(msk - (1<<i));
//            }
//            else {
//                sig = memo(msk, vals[i]==1);
//                printf("\t");
//                pmsk(msk);
//            }
//            printf(" %d => %d %d\n", vals[i]==1, sig.f, -sig.s);
//            ans = max(ans, {-sig.s + vals[i], -sig.f});
//        }
//    }

    return dp[msk][prev] = ans;
}

int main() {
    int dico[300];
    dico['r'] = 1;
    dico['y'] = 2;
    dico['g'] = 3;
    dico['o'] = 4;
    dico['u'] = 5;
    dico['p'] = 6;
    dico['a'] = 7;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        char tmp[20];
        scanf("%s", tmp);
        if(tmp[0] != 'b')
            vals[i] = dico[(int) tmp[0]];
        else
            vals[i] = dico[(int) tmp[2]];
        //printf("%d ", vals[i]);
    }
    // printf("\n");

    par ans = memo((1<<N)-1, 0);
    ans = max(ans, memo((1<<N)-1, 1));
    // printf("%d %d\n", ans.f, -ans.s);
    printf("%d\n", ans.f);
//    ans = memo((1<<N)-1, 1);
//    printf("%d %d\n", ans.f, -ans.s);
}
