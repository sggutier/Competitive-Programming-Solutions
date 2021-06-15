#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 105;

int calcFx(int N) {
    char brd[limN][limN];
    int ans = 0;
    for(int i=0; i<N; i++) {
        scanf("%s", brd[i]);
        for(int j=0; j<N; j++)
            ans += abs((i+j)%2 - brd[i][j]+'0');
    }
    return ans;
}

int main() {
    int N ;
    int perm[4], csts[4];
    int ans ;

    scanf("%d", &N);
    for(int i=0; i<4; i++) {
        perm[i] = i;
        csts[i] = calcFx(N);
    }

    ans = N*N*4;
    do {
        int s = 0;
        for(int i=0; i<4; i++)
            s += i%3==0? csts[perm[i]] : N*N - csts[perm[i]];
        ans = min(ans, s);
    } while(next_permutation(perm, perm+4));

    printf("%d\n", ans);
}
