#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;

vector <int> aprs[limN];

void testCase(int N, int Q) {
    for(int i=0; i<limN; i++)
        aprs[i].clear();
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        aprs[tmp-1].push_back(i);
    }
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a>(int) aprs[b-1].size()? 0: aprs[b-1][a-1]+1);
    }
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
