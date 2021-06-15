#include <bits/stdc++.h>
using namespace std;
const int limP = 60;
const int limN = 105;
const int limB = 1<<17;
#define f first
#define s second

vector <int> primos;

void criba(const int n = limP) {
    bitset <limP> usd;
    for(int i=2; i*i<n; i++)
        if(!usd[i])
            for(int j=i*i; j<n; j+=i)
                usd[j] = true;
    for(int i=2; i<n; i++)
        if(!usd[i])
            primos.push_back(i);
}

int N ;
int nums[limN];
int facs[limP+1];
bool usd[limN][limB];
pair<int, int> minSMemo[limN][limB];

int minS(int pos, int msk) {
    if(pos==-1)
        return 0;
    if(usd[pos][msk])
        return minSMemo[pos][msk].f;
    usd[pos][msk] = true;
    pair <int, int> &ans = minSMemo[pos][msk] ;
    ans.f = (1<<30);
    ans.s = -1;
    for(int x=2*nums[pos]-1; x>=1; x--)
        if( (msk & facs[x]) == 0)
            ans = min(ans,
                      {abs(x-nums[pos]) + minS(pos-1, msk | facs[x]), x} );
    return ans.f;
}

void reconst(int pos, int msk) {
    if(pos==-1) return;
    reconst(pos-1, msk | facs[minSMemo[pos][msk].s]);
    printf("%d ", minSMemo[pos][msk].s);
}

int main() {
    criba();
    for(int i=1; i<limP; i++) {
        for(int j=primos.size()-1; j>=0; j--)
            if(i % primos[j] == 0)
                facs[i] |= (1<<j);
        // printf("%d => %d\n", i, facs[i]);
    }
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    // printf("%d\n", minS(N-1, 0));
    minS(N-1, 0);
    reconst(N-1, 0);
    printf("\n");
}
