#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define num first
#define den second
const int limN = 1005;

int N ;
par shos[limN];
int idx[limN];

void testCase() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &shos[i].den, &shos[i].num);
        idx[i] = i;
    }

    sort(idx, idx+N, [] (int x, int y) {
            int a = shos[x].num * shos[y].den, b = shos[y].num * shos[x].den;
            if(a!=b)
                return a>b;
            return x<y;
        });

    for(int i=0; i<N; i++) {
        if(i)
            printf(" ");
        printf("%d", idx[i]+1);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
