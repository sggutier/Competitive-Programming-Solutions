#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
const int inf = 1e9;

typedef pair <int, int> pii;
typedef vector <pii> vii;

int N, Tx, Ty, X, Y, H, ANS;
map <pii, vii> M;

int aro[limN];
int LIS(vector<int> &V) {
    int W = 0;
    int ans = 0;
    aro[0] = inf;
    for(const int &n:V) {
        int pos = lower_bound(aro, aro+W, n) - aro;
        aro[pos] = n;
        W = max(W, pos+1);
        ans = max(ans, W);
    }
    return ans;
}

int main() {
    scanf("%d %d", &Tx, &Ty);
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &X, &Y, &H);
        X -= Tx, Y -= Ty;
        int G = __gcd(abs(X), abs(Y));
        X /= G, Y /= G;
        M[{X, Y}].push_back({G, H});
    }

    for(auto pt : M) {
        sort(pt.second.begin(), pt.second.end());

        vector <int> L(pt.second.size());
        for(int i=0;i<pt.second.size();i++)
            L[i] = pt.second[i].second;

        ANS += LIS(L);

//        for(int s : L)
//            printf("%d ", s);
//        printf("\n");
    }

    printf("%d\n", ANS);

    return 0;
}
