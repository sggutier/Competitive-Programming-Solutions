#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;

bool testCase(int N) {
    int stats[limN];

    for(int i=0; i<N; i++) {
        scanf("%d", &stats[i]);
    }

    sort(stats, stats+N);
    int pos = 0;
    for(int i=0; i<N; i++) {
        if(stats[i]-pos > 200)
            return false;
        pos = stats[i];
    }

    return (1422-pos)*2 < 200;
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("%s\n", testCase(n)? "POSSIBLE" : "IMPOSSIBLE");
    }
}
