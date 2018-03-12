#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limW = 1e6;

char linea[limW];

void testCase() {
    int numCnt = 0;
    int nums[limN];
    int ans = 0;
    char *pch ;

    gets(linea);

    pch = strtok (linea," ");
    while (pch != NULL) {
        //printf ("%s\n",pch);
        sscanf(pch, "%d", &nums[numCnt++]);
        pch = strtok (NULL, " ");
    }

    for(int i=1; i<numCnt; i++) {
        for(int j=0; j<i; j++)
            ans = max(ans, __gcd(nums[i], nums[j]));
    }
    printf("%d\n", ans);
}

int main() {
    int tc;

    gets(linea);
    sscanf(linea, "%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
