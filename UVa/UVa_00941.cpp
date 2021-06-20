#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limP = 20;
const int limN = 128;

ll pots[limP];

void precarga() {
    pots[0] = 1;
    for(int i=1; i<limP; i++)
        pots[i] = pots[i-1]*i;
}

ll comb(int n, int* cnts) {
    ll ans = pots[n];
    for(int i='a'; i<='z'; i++) {
        ans /= pots[cnts[i]];
    }
    return ans;
}

void testCase() {
    char str[25], tmp[25];
    int cnts[limN];
    ll k;
    int n ;
    gets(str);
    gets(tmp);
    k = atoll(tmp);
    n = strlen(str);
    sort(str, str+n);

    memset(cnts, 0, sizeof(cnts));
    for(int i=0; i<n; i++)
        cnts[(int) str[i]]++;
    // for(int i='a'; i<'z'; i++)
    //     if(cnts[i])
    //         printf("%c == %d\n", i, cnts[i]);

    for(int i=1; i<=n; i++) {
        ll tot = 0;
        int ult = -1;
        for(int c='a'; c<='z'; c++) {
            if(cnts[c]==0)
                continue;
            cnts[c]--;
            ll w = comb(n-i, cnts);
            cnts[c]++;
            ult = c;
            if(w+tot>k) {
                break;
            }
            tot += w;
        }
        cnts[ult]--;
        k -= tot;
        printf("%c", ult);
    }
    printf("\n");
}

int main() {
    precarga();
    char str[7];
    int tc;
    gets(str);
    tc = atoi(str);
    while(tc--)
        testCase();
}
