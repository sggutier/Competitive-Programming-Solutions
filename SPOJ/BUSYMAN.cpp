#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef pair<int,int> par;
#define f first
#define s second

int N ;
par evs[limN];
int maxE[limN];

void testCase() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &evs[i].f, &evs[i].s);
    sort(evs, evs+N);

    maxE[N] = 0;
    for(int i=N-1; i>=0; i--) {
        int sig = lower_bound(evs+i, evs+N, make_pair(evs[i].s, 0)) - evs;
        maxE[i] = max(maxE[i+1], 1 + maxE[sig]);
    }

    printf("%d\n", maxE[0]);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
