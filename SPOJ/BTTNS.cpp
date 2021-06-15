#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 21;

typedef bitset<LIM_N * LIM_N> bs;

int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
    int n = sz(A), rank = 0, br;
    assert(m <= sz(x));
    vi col(m); iota(all(col), 0);
    rep(i,0,n) {
        for (br=i; br<n; ++br) if (A[br].any()) break;
        if (br == n) {
            rep(j,i,n) if(b[j]) return -1;
            break;
        }
        int bc = (int)A[br]._Find_next(i-1);
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) if (A[j][i] != A[j][bc]) {
            A[j].flip(i); A[j].flip(bc);
        }
        rep(j,i+1,n) if (A[j][i]) {
            b[j] ^= b[i];
            A[j] ^= A[i];
        }
        rank++;
    }

    x = bs();
    for (int i = rank; i--;) {
        if (!b[i]) continue;
        x[col[i]] = 1;
        rep(j,0,i) b[j] ^= A[j][i];
    }
    return rank; // (multiple solutions if rank < m)
}

int R, C ;

inline int toId(const int r, const int c) {
    return r*C + c;
}

void testCase() {
    int K ;
    bs x ;
    scanf("%d%d%d", &R, &C, &K);
    vi b(R*C) ;
    vector <bs> A(R*C);
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            int a ;
            scanf("%d", &a);
            b[toId(i, j)] = a==1? 1 : 0;
        }
    }
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            for(int a=0; a < R; a++) {
                for(int b=0; b < C; b++) {
                    A[toId(a, b)][toId(i, j)] = abs(i-a) + abs(j-b) <= K;
                }
            }
        }
    }
    solveLinear(A, b, x, R*C);
    int cnt = 0 ;
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            int v = x[toId(i, j)];
            cnt += v;
            // printf("%d ", v);
        }
        // printf("\n");
    }
    // printf("===> ");
    printf("%d\n", cnt);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
