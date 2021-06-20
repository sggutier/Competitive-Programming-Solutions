#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9 ;
const int LIM_N = 20;
const int LIM_B = 1 << LIM_N;


int N ;
int N2, N2P;
int adj[LIM_N][LIM_N];
int NM, fullMsk ;
int ans ;

int totDst[LIM_N][LIM_B];
bool usd[LIM_N][LIM_B];
vector <int> izqs, ders;

void calcMinP() {
    for(int k=0; k < N; k++) {
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int memo(int pos, int msk) {
    if(usd[pos][msk]) {
        return totDst[pos][msk];
    }
    usd[pos][msk] = true;
    int &ans = totDst[pos][msk];
    if(msk == 0) {
        return ans;
    }
    msk ^= 1 << pos;
    for(int i=0; i < N; i++) {
        if((1 << i) & msk) {
            ans = min(ans, adj[pos][i] + memo(i, msk));
        }
    }
    return ans ;
}

void dfs(const int pos, const int msk, const int rem) {
    if(pos == NM || rem == 0) {
        for(int i=1; i < NM; i++)
            if((1 << i) & msk)
                memo(i, msk);
        return ;
    }
    dfs(pos+1, msk, rem);
    dfs(pos+1, msk | (1 << pos), rem - 1);
}

void findAns(const int pos, const int remA, const int remB, const int msk = 0, const int cmp = 0) {
    // printf("dfs at %d %d %d\n", pos, msk, rem);
    if(pos == NM) {
        int izqA = msk | 1 ;
        int izqB = msk | (1 << NM);
        int derA = cmp | (1 << NM) ;
        int derB = cmp | 1;
        // printf("%d >> %d\n", msk, cmp);
        // printf("%d vs %d  (with %d vs %d)\n", izqA, derA, izqB, derB);

        int minA = INF, minB = INF;
        for(const int i : izqs) {
            for(const int j : ders) {
                // printf("\t%d vs %d\n", i, j);
                // printf("\t\t< %d %d %d\n", adj[i][j], totDst[i][izqA], totDst[j][derA]);
                // printf("\t\t> %d %d %d\n", adj[i][j], totDst[i][izqB], totDst[j][derB]);
                minA = min(minA, adj[i][j] + totDst[i][izqA] + totDst[j][derA]);
                minB = min(minB, adj[i][j] + totDst[i][izqB] + totDst[j][derB]);
            }
        }

        ans = min(ans, minA + minB);
        return ;
    }
    if(remA) {
        izqs[N2 - remA] = pos ;
        findAns(pos+1, remA - 1, remB, msk | (1 << pos), cmp);
    }
    if(remB) {
        ders[N2P - remB] = pos ;
        findAns(pos+1, remA, remB - 1, msk, cmp | (1 << pos));
    }
}

void testCase(int E) {
    N2 = (N-2) / 2 ;
    N2P = (N-2) - N2;
    NM = N-1;
    fullMsk = (1 << NM) - 2;
    ans = INF;
    izqs.resize(N2);
    ders.resize(N2P);
    // cout << N2 << " " << N2P << endl;
    // cout << fullMsk << endl ;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++)
            adj[i][j] = INF;
        adj[i][i] = 0 ;
    }
    for(int i=0; i < N; i++) {
        for(int b=(1 << N) - 1; b >= 0; b--) {
            totDst[i][b] = INF;
            usd[i][b] = false;
        }
    }

    for(int i=0, a, b, c; i < E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    calcMinP();

    if(N == 3) {
        printf("%d\n", 2 * (adj[0][1] + adj[1][2]));
        return ;
    }

    totDst[0][1 << 0] = 0 ;
    totDst[NM][1 << NM] = 0 ;
    usd[0][1 << 0] = true ;
    usd[NM][1 << NM] = true ;
    dfs(1, 1 << 0, N2P);
    dfs(1, 1 << NM, N2P);
    // printf("---------\n");
    findAns(1, N2, N2P);

    printf("%d\n", ans);
}

int main() {
    int E ;
    int tc = 0 ;
    while(scanf("%d%d", &N, &E) != EOF) {
        printf("Case %d: ", ++tc);
        testCase(E);
    }
}
