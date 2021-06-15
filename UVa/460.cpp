#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int aLx, aLy, aRx, aRy;
    int bLx, bLy, bRx, bRy;
    scanf("%d%d%d%d", &aLx, &aLy, &aRx, &aRy);
    scanf("%d%d%d%d", &bLx, &bLy, &bRx, &bRy);
    aLx = max(aLx, bLx);
    aLy = max(aLy, bLy);
    aRx = min(aRx, bRx);
    aRy = min(aRy, bRy);
    if(aLx >= aRx || aLy >= aRy)
        printf("No Overlap\n");
    else
        printf("%d %d %d %d\n", aLx, aLy, aRx, aRy);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
