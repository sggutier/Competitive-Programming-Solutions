#include <bits/stdc++.h>
using namespace std;

void testCase(const int &T, const  int &w) {
    int bountyCnt;
    scanf("%d", &bountyCnt);
    int val[bountyCnt+1], timD[bountyCnt+1];
    vector<vector <char>> ant(bountyCnt+1, vector<char>(T+1, 0));
    vector<vector <int>> maxG(bountyCnt+1, vector<int>(T+1, 0));
    for(int i=1; i<=bountyCnt; i++) {
        scanf("%d%d", &timD[i], &val[i]);
    }
    //reverse(bounty+1, bounty + 1 + bountyCnt);
    for(int i=1; i<=bountyCnt; i++) {
        int d = 3*w*timD[i], v = val[i];
        maxG[i] = maxG[i-1];
        for(int j=d; j<=T; j++) {
            if(maxG[i][j] < maxG[i-1][j-d] + v) {
                maxG[i][j] = maxG[i-1][j-d] + v;
                ant[i][j] = 1;
            }
        }
        for(int j=1; j<=T; j++) {
            if(maxG[i][j-1] > maxG[i][j]) {
                maxG[i][j] = maxG[i][j-1];
                ant[i][j] = ant[i][j-1];
            }
        }
        // for(int j=0; j<=T; j++) {
        //     printf("%d ", maxG[i][j]);
        // }
        // printf("\n");
    }

    printf("%d\n", maxG[bountyCnt][T]);
    stack <int> ans;
    for(int i=bountyCnt, j=T; i>0; j-=ant[i][j]*3*w*timD[i], i--) {
        if(!ant[i][j])
            continue;
        ans.push(i);
    }
    printf("%d\n", (int) ans.size());
    while(!ans.empty()) {
        int ido = ans.top(); ans.pop();
        printf("%d %d\n", timD[ido], val[ido]);
    }
}

int main() {
    int a, b;
    int tc=0;

    while(scanf("%d%d", &a, &b)!=EOF) {
        if(tc++)
            printf("\n");
        testCase(a,b);
        // break;
    }
    
    return 0;
}
