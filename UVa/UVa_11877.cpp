#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int ans[limN];

void precarga() {
    ans[0] = 0;
    ans[2] = 1;
    for(int i=3; i<limN; i++) {
        ans[i] = ans[i/3 + i%3] + i/3;
    }
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n)
        printf("%d\n", ans[n]);
}
