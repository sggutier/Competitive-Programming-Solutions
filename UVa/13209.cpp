#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 3;

bool usd[limN];

void testCase(int N) {
    memset(usd, 0, sizeof(usd));
    int r = 1;
    int ans = 0;
    printf("0.");
    while(!usd[r]) {
        printf("%d", (r*10)/N);
        usd[r] = true;
        r = (r*10)%N;
        ans ++;
    }
    printf("\n");
}

int main() {
    int tc, n;

    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        testCase(n);
    }
}
