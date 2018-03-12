#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N;
string strs[limN];

void testCase() {
    char tmp[limN];
    int idx[limN];
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        strs[i] = tmp;
        idx[i] = i;
    }

    sort(idx, idx+N,
         [](int a, int b) {
             return strs[a].size() < strs[b].size(); });

    for(int i=1; i<N; i++) {
        int b = idx[i], a = idx[i-1];
        int w = strs[a].size();
        for(int j=0; j<w; j++) {
            if(strs[a][j]!=strs[b][j]) {
                printf("Impossible\n");
                return;
            }
        }
    }

    printf("%d\n", (int) strs[idx[N-1]].size());
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
