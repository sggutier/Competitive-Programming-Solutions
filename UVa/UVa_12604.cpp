#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 7927217405306359LL;
const ll MOD2 = 9898171296063599LL;
const int LIM_N = 5e5 + 5;
const int LIM_ALF = 128;

struct Mint {
    ll x, y, z ;
    Mint(const ll x) {
        this->x = this->y = this->z = x;
    }
    Mint(const ll x, const ll y) {
        this->x = x % MOD;
        this->y = y % MOD2;
    }
    Mint operator+(const Mint otr) {
        return Mint(
            this->x + otr.x,
            this->y + otr.y
        );
    }
    Mint operator*(const Mint otr) {
        return Mint(
            this->x * otr.x,
            this->y * otr.y
        );
    }
    Mint operator-(const Mint otr) {
        return Mint(
            this->x - otr.x + MOD,
            this->y - otr.y + MOD2
        );
    }
    bool operator==(const Mint otr) {
        return this->x == otr.x ;
    }
};

int tamAlf, tamPal, tamTxt;
char alfb[LIM_ALF];
char pal[LIM_N];
char txt[LIM_N];
char rev[LIM_ALF];
Mint potPal = 0;

void calculaRev(char *s) {
    for(int i=0; s[i]; i++) {
        rev[(int) s[i]] = i;
    }
}

void simplificaS(char *s, int lenS) {
    for(int i=0; i < lenS; i++) {
        s[i] = rev[(int) s[i]];
    }
}

void shiftea(char *s, int lenS, int BAS) {
    for(int i=0; i < lenS; i++) {
        s[i] = (s[i]+1) % BAS;
    }
}

Mint calcHash(char *s, int lenS, int BAS) {
    potPal = 1;
    Mint ans = 0;
    for(int i = 0; i < lenS; i++) {
        ans = ans*BAS + s[i];
        potPal = potPal * BAS;
    }
    return ans;
}

int numApr(const char *s, int lenS, const Mint hash, const int BAS, const int L) {
    Mint crg = 0;
    int ans = 0;
    for(int i = 0; i < lenS; i++) {
        crg = crg*BAS + s[i];
        if(i >= L) {
            crg = crg - potPal * s[i-L];
        }
        if(i >= L -1 && crg == hash) {
            ans ++;
            if(ans == 2) {
                return ans;
            }
        }
    }
    return ans;
}

void testCase() {
    scanf("%s", alfb); tamAlf = strlen(alfb);
    scanf("%s", pal); tamPal = strlen(pal);
    scanf("%s", txt); tamTxt = strlen(txt);

    calculaRev(alfb);
    simplificaS(pal, tamPal);
    simplificaS(txt, tamTxt);

    vector<int> ans;
    for(int i=0; i < tamAlf; i++) {
        Mint hash = calcHash(pal, tamPal, tamAlf);
        if(numApr(txt, tamTxt, hash, tamAlf, tamPal) == 1) {
            ans.push_back(i);
        }
        shiftea(pal, tamPal, tamAlf);
    }

    if(ans.size() == 0) {
        printf("no solution\n");
    }
    else if(ans.size() == 1) {
        printf("unique: %d\n", ans[0]);
    }
    else {
        printf("ambiguous:");
        for(const int x : ans) {
            printf(" %d", x);
        }
        printf("\n");
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}

