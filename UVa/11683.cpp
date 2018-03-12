#include <bits/stdc++.h>
using namespace std;

int calcDel(const vector<int> &blocks, int ini, int fin, int height) {
    if(ini==fin) {
        return height - blocks[ini];
    }
    int maxH = 0, ans = 0, ant=ini;
    for(int i=ini; i<=fin; i++) {
        maxH = max(maxH, blocks[i]);
    }
    ans = height-maxH;
    for(int i=ini; i<=fin; i++) {
        if(blocks[i]==maxH) {
            if(ant!=i)
                ans += calcDel(blocks, ant, i-1, maxH);
            ant = i+1;
        }
    }
    if(ant<=fin)
        ans += calcDel(blocks, ant, fin, maxH);
    return ans;
}

void testCase(int height) {
    int blockCnt;
    vector<int> blocks;

    scanf("%d", &blockCnt);
    blocks = vector<int>(blockCnt);
    for(int &b:blocks)
        scanf("%d", &b);

    printf("%d\n", calcDel(blocks, 0, blocks.size()-1, height));
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
    
    return 0;
}
