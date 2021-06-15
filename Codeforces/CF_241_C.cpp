#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<double> vd;
const double eps = 1e-12;
const int LIM_N = 1e5 + 5 ;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);

    rep(i,0,n) {
        double v, bv = 0;
        rep(r,i,n) rep(c,i,m)
            if ((v = fabs(A[r][c])) > bv)
                br = r, bc = c, bv = v;
        if (bv <= eps) {
            rep(j,i,n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);
        bv = 1/A[i][i];
        rep(j,i+1,n) {
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k,i+1,m) A[j][k] -= fac*A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j,0,i) b[j] -= A[j][i] * b[i];
    }
    return rank; // (multiple solutions if rank < m)
}


vd getRefls(const int l, const int r, const int N) {
    vector <vd> A(N);
    vd B(N);
    for(int i=0; i < N; i++) {
        A[i].resize(N);
        A[i][i] = l ;
        if(i + 1 < N) {
            A[i][i+1] = -l ;
            A[i][0] += 100 ;
        }
    }
    A[N-1][0] += N%2? r : 100 - r ;
    B[N-1] = 1e5 * l ;

    vd x(N) ;
    solveLinear(A, B, x);

    return x ;
}


int S ;
vector<pair<pii, int>> scrs[2];

int getScrs(int A, int B, int pos, int N) {
    int ans = 0 ;
    vector<pair<pii, int>>::iterator ps[] = {scrs[0].begin(), scrs[1].begin()};
    vd xs = getRefls(A, B, N);
    // printf("With pos = %d, A = %d, B = %d, N = %d\n\t", pos, A, B, N);
    // for(const double x : xs)
    //     printf("%.3lf " ,x);
    // printf("\n\t");
    for(const double x : xs) {
        while(ps[pos] != scrs[pos].end() && ps[pos]->first.second < x)
            ps[pos] ++ ;
        if(ps[pos] == scrs[pos].end() || ps[pos]->first.first > x) {
            // printf("\n");
            return 0 ;
        }
        // printf("%c (%d %d %d),  ", pos? 'T' : 'F', ps[pos]->first.first, ps[pos]->first.second, ps[pos]->second);
        ans += ps[pos]->second;
        ps[pos] ++ ;
        pos = 1 - pos ;
    }
    // printf("\n");
    return ans ;
}


int getScrs(int A, int B, int pos) {
    int ans = 0 ;
    for(int i = scrs[0].size() + scrs[1].size(); i; i --)
        ans = max(ans, getScrs(A, B, pos, i));
    return ans;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int A, B, S ;
    scanf("%d%d%d", &A, &B, &S);
    for(int i=0; i < S; i++) {
        char t ;
        int p, ini, fin;
        scanf("%d %c %d %d", &p, &t, &ini, &fin);
        scrs[t == 'T'].push_back({{ini, fin}, p});
    }
    sort(scrs[0].begin(), scrs[0].end());
    sort(scrs[1].begin(), scrs[1].end());

    printf("%d\n", max(getScrs(A, B, 0), getScrs(100 - A, 100 - B, 1)));
}
