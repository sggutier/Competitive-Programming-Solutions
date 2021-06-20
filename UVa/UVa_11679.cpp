#include <bits/stdc++.h>
using namespace std;

void testCase(int bankCnt, int cngCnt)  {
    vector <int> banks(bankCnt);

    for(auto &b:banks)
        scanf("%d", &b);

    while(cngCnt--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        banks[a-1] -= c;
        banks[b-1] += c;
    }

    for(const auto &b:banks) 
        if(b<0) {
            printf("N\n");
            return;
        }
    printf("S\n");
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        testCase(a,b);
    }

    return 0;
}
