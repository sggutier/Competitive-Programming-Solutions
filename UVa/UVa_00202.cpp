#include <bits/stdc++.h>
using namespace std;

void testCase(int a, int b) {
    vector <int> usd(b, 0);
    int ciclSt = -1;
    int cicLen = 0;
    int w = 0;

    printf("%d/%d = %d.", a, b, a/b);
    a %= b;

    for(int x=a; ; x=(x*10)%b) {
        if(usd[x]) {
            cicLen = w-usd[x]+1;
            ciclSt = x;
            break;
        }
        usd[x] = ++w;
    }

    w = min(50, w);
    for(int x=a; x!=ciclSt && w; x=(x*10)%b, w--) {
        printf("%d", (x*10)/b);
    }
    printf("(");
    for(int x=ciclSt; w; x=(x*10)%b, w--) {
        printf("%d", (x*10)/b);
    }
    if(cicLen>50)
        printf("...");
    printf(")\n");
    printf("   %d = number of digits in repeating cycle\n", cicLen);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF) {
        testCase(a, b);
        printf("\n");
    }
}
