#include <bits/stdc++.h>
using namespace std;

void testCase(int R, int C, int a, int b) {
    printf("%s\n", (a ^ b ^ (R-1-a) ^ (C-1-b))? "Gretel" : "Hansel");
}

int main() {
    int tc;
    int a, b, c, d;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        testCase(a, b, c, d);
    }
}
