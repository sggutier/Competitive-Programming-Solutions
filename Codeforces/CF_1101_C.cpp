#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
const int limN = 2e5 + 5;

pii sgms[limN];
int ords[limN];
int ans[limN];

void testCase() {
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &sgms[i].f, &sgms[i].s);
        ords[i] = i;
    }

    sort(ords, ords+N,
         [](const int a, const int b) {
             return sgms[a] < sgms[b];});

    int cnts[] = {0, 0};
    for(int i=0, j, w=0; i < N; i = j, w ^= 1) {
        int maxR = sgms[ords[i]].f;
        for(j=i; j<N && sgms[ords[j]].f <= maxR; j++) {
            // printf("%d %d => %d\n", sgms[ords[j]].f, sgms[ords[j]].s, maxR);
            ans[ords[j]] = w;
            cnts[w] ++;
            maxR = max(maxR, sgms[ords[j]].s);
        }
        // printf("----\n");
    }

    if(!cnts[1]) {
        printf("-1\n");
        return ;
    }

    for(int i=0; i<N; i++)
        printf("%d%c", ans[i]+1, i==N-1? '\n' : ' ');
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
