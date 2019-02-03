#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

int P, N;
ll A, B ;
int poss[2][limN];
int tots[2][limN];
ll csts[2][limN];

map <int, int> cubs;

int main() {
    scanf("%d%d", &P, &N);
    scanf("%lld%lld", &A, &B);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        a--;
        cubs[a]++;
    }
    N = 0;
    for(const auto &p : cubs) {
        poss[0][N] = p.first;
        tots[0][N] = p.second;
        csts[0][N] = B * p.second;
        N++;
    }

    int *pcur = poss[0], *psig = poss[1];
    int *tcur = tots[0], *tsig = tots[1];
    ll *ccur = csts[0], *csig = csts[1];
    int X = N, Y = 0;
    for(int p=1; p<=P; p++)  {
        Y = 0;
        for(int i=0; i<X; i++, Y++) {
            psig[Y] = (pcur[i]>>1);
            tsig[Y] = tcur[i];
            if(i+1 < X && psig[Y] == (pcur[i+1]>>1)) {
                tsig[Y] += tcur[i+1];
                csig[Y] = min(ccur[i] + ccur[i+1],
                              B * tsig[Y] * (1LL<<p));
                i++;
            }
            else {
                csig[Y] = min(A + ccur[i], B * tcur[i] * (1LL<<p));
            }
        }
        swap(pcur, psig);
        swap(tcur, tsig);
        swap(ccur, csig);
        swap(X, Y);
    }

    printf("%lld\n", ccur[0]);
}
