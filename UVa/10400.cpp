#include <bits/stdc++.h>
using namespace std;
const int limD = 32000;
const int limF = 4;
const int limN = 105;

vector <function<int(int, int)>> funcs;
char noms[7] = "+*-/";

char ant[limN][2*limD+1];

void testCase() {
    memset(ant, 0, sizeof(ant));
    int ult;
    int numCnt; scanf("%d", &numCnt);
    vector <int> nums(numCnt);
    for(int i=0; i<numCnt; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &ult);

    ant[0][nums[0] + limD] = 1;
    for(int i=1; i<numCnt; i++) {
        for(int j=-limD; j<=limD; j++) {
            if(!ant[i-1][j+limD])
                continue;
            // printf("%d <= %d\n", nums[i], j);
            // printf("[");
            for(int d=0; d<4; d++) {
                int sig = funcs[d](j, nums[i]);
                if(abs(sig)>limD)
                    continue;
                // printf("(%c %d)", noms[d], sig);
                ant[i][sig+limD] = d+1;
            }
            // printf("]\n");
        }
    }

    if(!ant[numCnt-1][ult + limD]) {
        printf("NO EXPRESSION\n");
        return;
    }
    int pos = ult;
    // printf("%d", pos);
    stack <char> ans;
    for(int i=numCnt-1; i>0; i--) {
        int d = ant[i][pos + limD] - 1;
        ans.push(noms[d]);
        pos = funcs[(d+2)%4](pos, nums[i]);
        // printf(" => %d %d ", d, pos);
    }
    // printf("\n");
    printf("%d", nums[0]);
    for(int i=1; i<numCnt; i++) {
        printf("%c%d", ans.top(), nums[i]);
        ans.pop();
    }
    printf("=%d\n", ult);
}

int main() {
    funcs.push_back([&](const int &x, const int &y) -> int { return x + y; });
    funcs.push_back([&](const int &x, const int &y) { return x * y; });
    funcs.push_back([&](const int &x, const int &y) { return x - y; });
    funcs.push_back([&](const int &x, const int &y) { return (y==0 || x%y!=0)? limD+1 : x/y; });

    // printf("%s\n", noms);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
    
    return 0;
}
