#include <bits/stdc++.h>
using namespace std;

__int128 lee128() {
    char c;
    __int128 ans = 0;
    while(scanf("%c", &c)!=EOF && !isdigit(c));
    ans += c-'0';
    while(scanf("%c", &c)!=EOF && isdigit(c)) {
        ans = ans*10 + c-'0';
    }
    return ans;
}

void imprime128(__int128 n) {
    if(n/10 != 0)
        imprime128(n/10);
    printf("%d", (int) (n%10));
}

void testCase(int a, int b) {
    __int128 sum = 0;
    while(a--) {
        sum += lee128();
    }
    imprime128(sum);
    printf(": each friend should pay ");
    imprime128(sum/b);
    printf("\n\n");
}

int main() {
    int a, b;
    int tc = 1;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Bill #%d costs ", tc++);
        testCase(a, b);        
    }
}
