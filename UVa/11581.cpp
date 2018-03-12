#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int last[(1<<9)];

int encode(char S[3][5]) {
    int ans = 0;
    for(int i=0; i<9; i++)
        ans += (S[i/3][i%3]<<i);
    return ans;
}

void modify(char S[3][5]) {
    char cpy[3][5];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cpy[i][j] = 0;
            for(int d=0; d<4; d++) {
                int r=i+dr[d], c=j+dc[d];
                if(0<=r && r<3 && 0<=c && j<3) {
                    cpy[i][j] = (cpy[i][j] + S[r][c])%2;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            S[i][j] = cpy[i][j];
}

int testCase() {
    memset(last, 0, sizeof(last));
    char S[3][5];
    for(int i=0; i<3; i++) {
        scanf("%s", S[i]);
        for(int j=0; j<3; j++)
            S[i][j] -= '0';
    }
    int w = 1;
    while(true) {
        // printf("[%d]\n", w-1);
        // for(int i=0; i<3; i++) {
        //     for(int j=0; j<3; j++)
        //         printf("%d ", S[i][j]);
        //     printf("\n");
        // }        
        int pos = encode(S);
        if(last[pos])
            return last[pos]-2;
        last[pos] = w++;
        modify(S);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        printf("%d\n", testCase());
    
    return 0;
}
