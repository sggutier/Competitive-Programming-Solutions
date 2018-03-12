#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define ll int
const ll mod1 = (1<<19)-1;
// const ll mod2 = 1e9 + 7;
// const ll mod2 = 1e8 + 7;
const ll mod2 = (1LL<<31)-1;
// const ll mod1 = 1 ;
// const ll mod2 = (1<<19)-1;
// const int mod1 = 1229;
// const int mod2 = 4321;
const int limS = 5e5 + 5;
const int limW = 5e4 + 5;
const int limA = 70;

// map <ll, int> aprs;
// int aprs[mod1][mod2];
map <ll, int> aprs[mod1];
char A[limA], W[limW], S[limS];
int revr[300];

void testCase() {
    // aprs.clear();
    for(int i=mod1; i>=0; i--)
    //     aprs[i].clear();
        aprs[i] = map<ll, int>();
    // memset(aprs, 0, sizeof(aprs));
    int tamA, tamW, tamS;
    ll pot1 = 1, pot2 = 1;
    ll num1 = 0, num2 = 0;

    scanf("%s", A); tamA = strlen(A);
    scanf("%s", W); tamW = strlen(W);
    scanf("%s", S); tamS = strlen(S);
    
    for(int i=0; i<tamW; i++) {
        pot1 = (pot1*tamA)%mod1;
        pot2 = (pot2*tamA)%mod2;
    }
    pot1 = (mod1-pot1)%mod1;
    pot2 = (mod2-pot2)%mod2;
    
    for(int i=0; i<tamA; i++)
        revr[(int) A[i]] = i;
    for(int i=0; i<tamW; i++)
        W[i] = revr[(int) W[i]];
    for(int i=0; i<tamS; i++) {
        S[i] = revr[(int) S[i]];
        num1 = (num1*tamA + S[i])%mod1;
        num2 = (num2*tamA + S[i])%mod2;
        if(i>=tamW) {
            num1 = (num1 + (pot1*S[i-tamW])%mod1)%mod1;
            num2 = (num2 + (pot2*S[i-tamW])%mod2)%mod2;
        }
        if(i>=tamW-1) {
            aprs[num1][num2] ++;
            // aprs[num1*mod2 + num2] ++;
            // printf("Codin %lld %lld => %lld\n", num1, num2, num1*mod2 + num2);
        }
    }

    list <int> ans;
    for(int sft=0; sft<tamA; sft++) {
        num1 = 0;
        num2 = 0;
        for(int i=0; i<tamW; i++) {
            num1 = (num1*tamA + W[i])%mod1;
            num2 = (num2*tamA + W[i])%mod2;
            W[i] = (W[i]+1)%tamA;
        }
        // auto it = aprs.find(num1*mod2 + num2);
        auto it = aprs[num1].find(num2);
        if(it!=aprs[num1].end() && it->second==1)
            ans.push_back(sft);
        // if(aprs[num1][num2]==1)
        //     ans.push_back(sft);
    }
    if(ans.size()==0) {
        printf("no solution\n");
    }
    else if(ans.size()==1)
        printf("unique: %d\n", *ans.begin());
    else {
        printf("ambiguous:");
        for(const int &a:ans)
            printf(" %d", a);
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

