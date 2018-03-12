#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e5 + 5;

ll lets[300];

void precarga() {
    ll pots3[65];
    ll ans[64];

    pots3[0] = 1;
    for(int i=0; i<64; i++)
        pots3[i+1] = (pots3[i]*3)%mod;
    for(int i=0; i<64; i++) {
        int c = 0;
        for(int b=0; b<6; b++) {
            if(((1<<b) & i) == 0)
                c ++;
        }
        ans[i] = pots3[c];
    }

    for(int i='0'; i<='9'; i++)
        lets[i] = ans[i-'0'+0];
    for(int i='A'; i<='Z'; i++)
        lets[i] = ans[i-'A'+10];
    for(int i='a'; i<='z'; i++)
        lets[i] = ans[i-'a'+36];
    lets['-'] = ans[62];
    lets['_'] = ans[63];
}

int main(){
    precarga();
    char str[limN];
    ll ans = 1;
    fgets(str, limN, stdin);
    for(char *c=str; *c!='\n' && *c; c++)
        ans = (ans*lets[(int) *c])%mod;
    printf("%d\n", (int) ans);
}
