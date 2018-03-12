#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int N, M ;
int mat[limN][limN];
int cnt[limN];

int main() {
    pair <int, int> a;

    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++) {
        a = make_pair(-1, 0);
        for(int j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
            a = max(a, make_pair(mat[i][j], -j));
        }
        cnt[-a.second]++;
    }

    a = make_pair(-1, 0);
    for(int i=0; i<N; i++)
        a = max(a, make_pair(cnt[i], -i));

    printf("%d\n", -a.second + 1);
}
