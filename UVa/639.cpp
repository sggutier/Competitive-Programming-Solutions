#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int ans;

inline bool isValidPos(int r, int c, int n) {
    return 0<=r && r<n && 0<=c && c<n;
}

bool goodPlace(char** board, const int &bSize, int r, int c) {
    for(int d=0; d<4; d++) {
        for(int i=1; isValidPos(r + i*dr[d], c + i*dc[d], bSize); i++) {
            if(board[r + i*dr[d]][c + i*dc[d]]=='X')
                break;
            else if(board[r + i*dr[d]][c + i*dc[d]]=='#')
                return false;
        }
    }
    return true;
}

void tryAllConfigs(char** board, const int &bSize, int rookCnt) {
    ans = max(ans, rookCnt);
    for(int i=0; i<bSize; i++) {
        for(int j=0; j<bSize; j++) {
            if(board[i][j]!='.' || !goodPlace(board, bSize, i, j))
                continue;
            board[i][j] = '#';
            tryAllConfigs(board, bSize, rookCnt+1);
            board[i][j] = '.';
        }
    }
}

void testCase(const int &bSize) {
    char **board = new char*[bSize];
    for(int i=0; i<bSize; i++)
        board[i] = new char[bSize+5];

    ans = 0;
    for(int i=0; i<bSize; i++)
        scanf("%s", board[i]);

    tryAllConfigs(board, bSize, 0);

    printf("%d\n", ans);

    for(int i=0; i<bSize; i++)
        delete[] board[i];
    delete[] board;
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
