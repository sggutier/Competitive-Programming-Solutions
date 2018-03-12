#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;


void testCase(int N) {
    //memset(usd, 0, sizeof(usd));
    bitset <limN> usd;

    //int pos = 0, tim = 0;
    int pos = N, tim = 0;
    while(!usd[pos]) {
        usd[pos] = true; tim++;
        pos = ((pos*pos)/100)%10000;
    }

    printf("%d\n", tim);
}

int main() {
    int N;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
}
