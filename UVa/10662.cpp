#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);

void lee(int N, int W, vector<vector<int>> &works, int *n) {
    for(int i=0; i<N; i++) {
        scanf("%d", &n[i]);
        for(int j=0; j<W; j++) {
            scanf("%d", &works[i][j]);
            works[i][j] = 1-works[i][j];
        }
    }
}

void testCase(int T, int R, int H) {
    vector<vector<int>> tworks(T, vector<int>(R)), rworks(R, vector<int>(H)), hworks(H, vector<int>(T));
    int t[T], r[R], h[H];
    int ans = inf, ansT, ansR, ansH;

    lee(T, R, tworks, t);
    lee(R, H, rworks, r);
    lee(H, T, hworks, h);

    for(int i=0; i<T; i++) {
        for(int j=0; j<R; j++) {
            for(int k=0; k<H; k++) {
                if(!(tworks[i][j] && rworks[j][k] && hworks[k][i]))
                    continue;
                int sum = t[i] + r[j] + h[k];
                if(sum<ans) {
                    ans = sum;
                    ansT = i;
                    ansR = j;
                    ansH = k;
                }
            }
        }
    }
    
    if(ans==inf)
        printf("Don't get married!\n");
    else
        printf("%d %d %d:%d\n", ansT, ansR, ansH, ans);
}

int main() {
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF)
        testCase(a, b, c);
    
    return 0;
}
