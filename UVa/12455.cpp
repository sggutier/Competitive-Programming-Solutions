#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int barLen;
    int barCnt;
    scanf("%d%d", &barLen, &barCnt);
    vector <bool> usd(barLen+1);
    usd[0] = true;
    while(barCnt--) {
        int a;
        scanf("%d", &a);
        for(int i=barLen; i>=a; i--)
            if(usd[i-a])
                usd[i] = true;
    }
    printf("%s\n", usd[barLen]? "YES" : "NO");
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
