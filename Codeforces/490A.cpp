#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

queue <int> poss[4];

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        poss[a].push(i);
    }

    printf("%d\n", (int) min(poss[1].size(), min(poss[2].size(), poss[3].size()) ) );
    while(min(poss[1].size(), min(poss[2].size(), poss[3].size()) ) > 0) {
        printf("%d %d %d\n", poss[1].front(), poss[2].front(), poss[3].front());
        poss[1].pop();
        poss[2].pop();
        poss[3].pop();
    }
}
