/*
ID: me60
LANG: C++11
TASK: barn1
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int M, S, C;
    int lugares[1000];
    int minTapados[1000][55];

    scanf("%d%d%d", &M, &S, &C);
    for(int i=0; i<C; i++)
        scanf("%d", &lugares[i]);

    sort(lugares, lugares+C);
    for(int i=1; i<=M; i++)
        minTapados[0][i] = 1;
    for(int i=1; i<C; i++) {
        minTapados[i][1] = minTapados[i-1][1] + lugares[i] - lugares[i-1] ;
        for(int j=2; j<=M; j++) {
            minTapados[i][j] = min(minTapados[i][j-1],
                                 min(minTapados[i-1][j] + lugares[i] - lugares[i-1],
                                     minTapados[i-1][j-1] + 1));
        }
    }

    printf("%d\n", minTapados[C-1][M]);

    return 0;
}
