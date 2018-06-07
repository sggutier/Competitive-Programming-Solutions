#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define r first
#define c second
const int limN = 300*300 + 5;
const int inf = 1e9 + 5;

int dst(const pii A, const pii B) {
    return abs(A.r - B.r) + abs(A.c - B.c);
}

vector <pii> poss[limN];
vector<int> minDst[limN];

int main() {
    int R, C, K;

    scanf("%d%d%d", &R, &C, &K);
    for(int i=0; i<R; i++) {
        for(int j=0, w; j<C; j++) {
            scanf("%d", &w);
            minDst[w].push_back(w==1? dst({0,0}, {i,j})  : inf);
            poss[w].push_back({i, j});
        }
    }

    for(int w=1; w<K; w++) {
        int n = poss[w].size(), m = poss[w+1].size();
        vector <int> ord;
        for(int i=0; i<n; i++) {
            ord.push_back(i);
        }
        sort(ord.begin(), ord.end(),
             [&w] (int a, int b) { return minDst[w][a] < minDst[w][b]; });
        int maxK = inf;
        for(int i : ord) {
            // printf("%d %d => %d (%d)\n", w, i, minDst[w][i], maxK);
            if(minDst[w][i] > maxK)
                break;
            for(int j=0; j<m; j++) {
                minDst[w+1][j] = min(minDst[w+1][j],
                                     minDst[w][i] + dst(poss[w][i], poss[w+1][j]));
                maxK = max(maxK, minDst[w+1][j]);
            }
        }
    }    

    printf("%d\n", minDst[K][0]);
}
