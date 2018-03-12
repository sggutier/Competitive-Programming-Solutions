#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int limN = 2e5 + 5;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e8 + 7;
const ll alphSiz = 26;

char str[limN];
ll sumL1[limN], sumR1[limN], sumL2[limN], sumR2[limN];
ll modPots1[limN], modPots2[limN];

void testCase();
void precarga(ll mod, ll *pots);
void calcHashes(int strSiz, ll mod, ll *sum) ;
bool isPalindrome(int ini, int fin) ;
inline bool hashMatches(int ini, int fin, int mitIni, int mitFin, int dst, ll *sumL, ll *sumR, ll *modPots);

int main() {
    precarga(mod1, modPots1);
    precarga(mod2, modPots2);

    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}

void testCase() {
    scanf("%s", str+1);    
    int n = strlen(str+1);

    for(int i=1; i<=n; i++)
        str[i] -= 'a';
    sumR2[n+1] = sumR1[n+1] = 0;
    
    calcHashes(n, mod1, sumL1);
    calcHashes(n, mod2, sumL2);
    reverse(str+1, str+n+1);
    calcHashes(n, mod1, sumR1);
    calcHashes(n, mod2, sumR2);
    reverse(sumR1+1, sumR1+n+1);
    reverse(sumR2+1, sumR2+n+1);

    // for(int i=1; i<=n; i++)
    //     printf("%lld ", sumL1[i]);
    // printf("\n");
    // for(int i=1; i<=n; i++)
    //     printf("%lld ", sumR1[i]);
    // printf("\n");
    // for(int i=1; i<=n; i++)
    //     printf("%lld ", sumL2[i]);
    // printf("\n");
    // for(int i=1; i<=n; i++)
    //     printf("%lld ", sumR2[i]);
    // printf("\n");

    for(int i=1; i<n; i++) {
        if(isPalindrome(1, i) && isPalindrome(i+1, n)) {
            printf("alindrome\n");
            return;
        }
    }
    if(isPalindrome(1, n))
        printf("palindrome\n");
    else
        printf("simple\n");
}

bool hashMatches(int ini, int fin, int mitIni, int mitFin, int dst, ll *sumL, ll *sumR, ll mod, ll *modPots) {
    return (sumL[mitIni]+(mod - (sumL[ini]*modPots[dst])%mod))%mod ==
        (sumR[mitFin]+(mod - (sumR[fin]*modPots[dst])%mod))%mod;
}

bool isPalindrome(int ini, int fin) {
    int dst = (fin-ini)/2;
    int mitIni = ini+dst, mitFin = fin-dst;
    ini--, fin++;
    dst ++;
    return hashMatches(ini, fin, mitIni, mitFin, dst, sumL1, sumR1, mod1, modPots1) &&
        hashMatches(ini, fin, mitIni, mitFin, dst, sumL2, sumR2, mod2, modPots2);
}

void calcHashes(int strSiz, ll mod, ll *sum) {
    for(int i=1; i<=strSiz; i++)
        sum[i] = (sum[i-1]*alphSiz + str[i])%mod;
}

void precarga(ll mod, ll *pots) {
    pots[0] = 1 ;
    for(int i=1; i<limN; i++)
        pots[i] = (pots[i-1]*alphSiz)%mod;
}
