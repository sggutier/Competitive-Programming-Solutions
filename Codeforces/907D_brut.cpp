#include <bits/stdc++.h>
using namespace std;

int R, C ;
int RC;
vector<vector<int>> ans;
set <int> usd;

void toNum(const int k, int &r, int &c) {
    r = (k-1) / C + 1;
    c = (k-1) % C + 1;
}

bool togtr(const int a, const int b) {
    // printf("%d vs %d\n", a, b);
    int r, c, x, y;
    toNum(a, r, c);
    toNum(b, x, y);
    // printf("\t%d %d\n", r, c);
    // printf("\t%d %d\n", x, y);
    return abs(r-x) + abs(y-c) == 1;
}

void bruta(const int pos = 1) {
    if(RC < pos) {
        printf("YES\n");
        for(int i=1; i <= R; i++) {
            for(int j=1; j <= C; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    int r, c ;
    toNum(pos, r, c);
    // printf("> %d %d\n", r, c);
    for(auto it = usd.begin(); it != usd.end(); it++) {
        int k = *it;
        if((1 < r && togtr(k, ans[r-1][c]))
           || (1 < c && togtr(k, ans[r][c-1])))
            continue;
        // printf("%d %d => %d\n", r, c, k);
        usd.erase(it);
        ans[r][c] = k;
        bruta(pos+1);
        usd.insert(k);
        it = usd.find(k);
    }
}

int main() {
    scanf("%d%d", &R, &C);
    RC = R * C ;
    for(int i=0; i <= R; i++) {
        ans.push_back(vector<int>(C+1));
    }
    for(int i=1; i <= RC; i++)
        usd.insert(i);
    bruta();
    printf("NO\n");
}
