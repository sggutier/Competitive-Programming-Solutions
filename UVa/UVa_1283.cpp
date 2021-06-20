#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 105;
const __int128 uno = 1;

int N ;
__int128 fullMsk;
__int128 msks[LIM_N];
vector <int> ans ;
int tgt ;
int nums[10];

void bruta(int pos=0, __int128 msk = 0, int np = 0) {
    if(msk == fullMsk) {
        for(int i=0; i < tgt; i++)
            ans.push_back(nums[i]);
        return ;
    }
    if(pos == N || np == tgt)
        return ;
    bruta(pos+1, msk, np);
    if(!ans.empty())
        return ;
    nums[np] = pos;
    bruta(pos+1, msk | msks[pos], np + 1);
}

void testCase() {
    char S[LIM_N];

    for(int i=0; i < N; i++) {
        scanf("%s", S);
        msks[i] = uno << i;
        for(int j=0; j < N; j++)
            if(S[j] == '1')
                msks[i] |= uno << j;
    }

    ans.clear();
    fullMsk = (uno << N) - 1;

    for(int i=1; i <= 5; i++) {
        tgt = i ;
        bruta();
        if(!ans.empty())
            break;
    }

    printf("%d", (int) ans.size());
    for(const int x : ans)
        printf(" %d", x + 1);
    printf("\n");
}

int main() {
    int tc = 0 ;
    while(scanf("%d", &N) != EOF) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}
