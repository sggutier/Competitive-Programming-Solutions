//
// Created by mpc-tlj on 21/03/19.
//

#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;
// typedef long long ll;
// const ll modC = 1e9 + 7;
// const ll modB = 123891739;
// const ll modA = 1e8 + 7;
typedef unsigned long long ll;

struct Mod {
    // ll xA;
    // ll xB;
    ll xC ;
    Mod() {}
    Mod(const ll a) {
        // xA = (a + modA) % modA;
        // xB = (a + modB) % modB;
        // xC = (a + modC) % modC;
        xC = a;
    }
    // Mod(
    //     const ll x,
    //     const ll y,
    //     const ll z) {
    //     xA = (modA + x) % modA;
    //     xB = (modB + y) % modB;
    //     xC = (modC + z) % modC;
    // }
};
// const Mod bas = Mod(10);
const Mod bas = Mod(500001);

Mod operator-(const Mod A, const Mod B) {
    return Mod(
               // A.xA - B.xA,
               // A.xB - B.xB,
               A.xC - B.xC);
}

Mod operator+(const Mod A, const Mod B) {
//    printf("%lld %lld %lld | %lld %lld %lld\n", A.xA, A.xB, A.xC, B.xA, B.xB, B.xC);
    return Mod(
               // A.xA + B.xA,
               // A.xB + B.xB,
               A.xC + B.xC);
}

Mod operator*(const Mod A, const Mod B) {
    return Mod(
               // A.xA * B.xA,
               // A.xB * B.xB,
               A.xC * B.xC);
}

bool operator<(const Mod A, const Mod B) {
    // if(A.xA != B.xA)
    //     return A.xA < B.xA;
    // if(A.xB != B.xB)
    //     return A.xB < B.xB;
    return A.xC < B.xC;
}

bool operator==(const Mod A, const Mod B) {
    return
        // A.xA == B.xA
        // && A.xB == B.xB
        // &&
        A.xC == B.xC;
}

int A, B ;
int nums[limN], otro[limN];
Mod smsL[limN], smsR[limN] ;
Mod pots[limN], acums[limN];
vector <int> lapr[limN];

bool query(int a, int b, int len) {
    a--, b--;
    int fa = a + len, fb = b + len;
    Mod pa = smsL[a], pb = smsR[b];
    Mod ra = smsL[fa] - pa*pots[len];
    Mod rb = smsR[fb] - pb*pots[len];
    if(ra == rb)
        return true;
    int ini = 1, fin = len;
    int piv;
    while(ini < fin) {
        piv = (ini + fin) / 2;
        if(smsL[a + piv] - pa*pots[piv] == smsR[b + piv] - pb*pots[piv])
            ini = piv + 1;
        else
            fin = piv;
    }
    Mod w = Mod(otro[b + ini] - nums[a + ini]);
    int tip = nums[a + ini];
    
    // for(int x=a+1; x!=fa; x++)
    //     printf("%d ", nums[x]);
    // printf("%d\n", nums[fa]);
    // for(int x=b+1; x!=fb; x++)
    //     printf("%d ", otro[x]);
    // printf("%d\n", otro[fb]);
    // printf("%d distinto en %d\n", tip, ini);
    // printf("\t%lld vs %lld\n", (smsL[a + ini]).xC, (smsR[b + ini]).xC);
    
    int p = upper_bound(lapr[tip].begin(), lapr[tip].end(), a) - lapr[tip].begin();
    p = lapr[tip][p-1];
    int q = upper_bound(lapr[tip].begin(), lapr[tip].end(), fa) - lapr[tip].begin();
    q = lapr[tip][q-1];
    
    // printf("\t %d %d\n", p, q);
    // for(const int r : lapr[tip])
    //     printf("%d ", r);
    // printf("\n");
    
    Mod z = (acums[q] - acums[p]*pots[q-p]) * pots[fa-q];
    
    // printf("\tz: %lld\n", z.xC);
    // printf("\tw: %lld\n", w.xC);
    // printf("\tra: %lld\n", ra.xC);
    // printf("\trb: %lld\n", rb.xC);
    
    return ra + z*w == rb;
}

int main() {
    pots[0] = Mod(1);
    for(int i=1; i<limN; i++)
        pots[i] = pots[i-1] * bas;

    for(int i=0; i<limN; i++)
        lapr[i].push_back(0);

    scanf("%d", &A);
    smsL[0] = Mod(0);
    for(int i=1; i<=A; i++) {
        scanf("%d", &nums[i]);        
        smsL[i] = Mod(nums[i]) + smsL[i-1] * bas;
        int p = *(lapr[nums[i]].end()-1);
        acums[i] = Mod(1) + acums[p]*pots[i-p];
        lapr[nums[i]].push_back(i);
    }
    scanf("%d", &B);
    smsR[0] = Mod(0);
    for(int i=1; i<=B; i++) {
        scanf("%d", &otro[i]);
        smsR[i] = Mod(otro[i]) + smsR[i-1] * bas;
    }

    int Q ;
    scanf("%d", &Q);
    for(int i=1; i<=Q; i++) {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        // printf("quer: %d %d %d\n", a, b, len);
        printf("%s\n", query(a, b, len)? "TAK" : "NIE");
    }
    
}
