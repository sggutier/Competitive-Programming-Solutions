#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e8 + 7;
const ll tam = 29;
const int limN = 1e5 + 5;

ll pots1[limN], pots2[limN];
map <pair<int, int>,int> aprs;

void hazTab(ll mod, int N, char *str, ll *tab) {
    tab[0] = 0;
    for(int i=0; i<N; i++)
        tab[i+1] = (tab[i]*tam + str[i]-'a'+1)%mod;
}

int tonm(ll *pots, ll mod, int N, ll *tab, int i, int c) {
    ll res = (tab[N] + (((mod - tab[i])%mod) *pots[N-i])%mod ) % mod;
    // printf("%d %d => %lld\n", i, c, (((tab[i]*tam + c)%mod)*pots[N-i] + res) % mod);
    return (((tab[i]*tam + c)%mod)*pots[N-i] + res) % mod;
}

int tora(ll *pots, ll mod, int N, ll *tab, int i) {
    ll res = (tab[N] + (((mod - tab[i])%mod) *pots[N-i])%mod ) % mod;
    //printf("%d %lld => %lld %lld\n", i, tab[N], res, (tab[i-1]*pots[N-i] + res) % mod);
    return ((tab[i-1]*pots[N-i])%mod + res) % mod;
}

int main() {
    int N ;
    char strA[limN], strB[limN];
    ll tabA1[limN], tabB1[limN];
    ll tabA2[limN], tabB2[limN];
    set<pair<int,int> > ans ;
    int difCnt = 0;    

    scanf("%d", &N);
    scanf("%s", strA);
    scanf("%s", strB);

    pots1[0] = pots2[0] = 1;
    for(int i=0; i<N; i++) {
        pots1[i+1] = (pots1[i]*tam)%mod1;
        pots2[i+1] = (pots2[i]*tam)%mod2;
        if(strA[i]!=strB[i])
            difCnt++;
    }

    if(difCnt == 1) {
        printf("2\n");
        return 0;
    }

    hazTab(mod1, N, strA, tabA1);
    hazTab(mod1, N, strB, tabB1);
    hazTab(mod2, N, strA, tabA2);
    hazTab(mod2, N, strB, tabB2);

    for(int i=0; i<N; i++) {
        //aprs.insert(tora(N, tabA, i+1));
        aprs[{tora(pots1, mod1, N, tabA1, i+1), tora(pots2, mod2, N, tabA2, i+1)}] = i;
    }
    for(int i=0; i<N; i++) {
        auto it = aprs.find({tora(pots1, mod1, N, tabB1, i+1), tora(pots2, mod2, N, tabB2, i+1)});
        if(it==aprs.end())
            continue;
        // printf("hehehe %c %c\n", strA[it->second], strB[i]);
        // printf("%d %d\n", tonm(N, tabB, it->second+1, strA[it->second]-'a'+1), tonm(N, tabA, i, strB[i]-'a'+1));
        // printf("%d %d\n", tonm(N, tabB, it->second, strA[it->second]-'a'+1), tonm(N, tabA, i+1, strB[i]-'a'+1));
        if((tonm(pots1, mod1, N, tabB1, it->second+1, strA[it->second]-'a'+1) == tonm(pots1, mod1, N, tabA1, i, strB[i]-'a'+1)) &&
           (tonm(pots2, mod2, N, tabB2, it->second+1, strA[it->second]-'a'+1) == tonm(pots2, mod2, N, tabA2, i, strB[i]-'a'+1))){
            // ans++;
            ans.insert({tonm(pots1, mod1, N, tabB1, it->second+1, strA[it->second]-'a'+1),
                        tonm(pots2, mod2, N, tabB2, it->second+1, strA[it->second]-'a'+1)});
        }
        if((tonm(pots1, mod1, N, tabB1, it->second, strA[it->second]-'a'+1) == tonm(pots1, mod1, N, tabA1, i+1, strB[i]-'a'+1)) &&
           (tonm(pots2, mod2, N, tabB2, it->second, strA[it->second]-'a'+1) == tonm(pots2, mod2, N, tabA2, i+1, strB[i]-'a'+1))){
            // ans++;
            ans.insert({tonm(pots1, mod1, N, tabB1, it->second, strA[it->second]-'a'+1),
                        tonm(pots2, mod2, N, tabB2, it->second, strA[it->second]-'a'+1)});
        }
    }

    // for(int i=0; i<N; i++) {
    //     for(int c=0; c<tam; c++) {
    //         aprs.insert(tonm(N, tabA, i, c));
    //         aprs.insert(tonm(N, tabA, i+1, c));
    //     }
    // }

    // for(int i=0; i<=N; i++) {
    //     if(strA[i]==strB[i])
    //         continue;
    //     for(int c=0; c<tam; c++) {
    //         auto it = aprs.find(tonm(N, tabB, i, c));
    //         if(it==aprs.end())
    //             continue;
    //         ans++;
    //         aprs.erase(it);
    //     }
    // }

    printf("%d\n", (int) ans.size());
}
