#include <bits/stdc++.h>
using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

inline bool insideLims(int r, int c, int rows, int cols) {
    return 0 <= r && r<rows && 0<=c && c<cols;
}

int maxSlideFromPos(int rows, int cols, int mapa[][100], int r, int c, int precMaxSlides[][100]) {
    if(precMaxSlides[r][c]) {
        return precMaxSlides[r][c];
    }
    int ans = 0;
    for(int d=0; d<4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if(insideLims(nr, nc, rows, cols) && mapa[r][c] > mapa[nr][nc])
            ans = max(ans, maxSlideFromPos(rows, cols, mapa, nr, nc, precMaxSlides));
    }
    return precMaxSlides[r][c] = ans+1;
}

int maxSlide(int rows, int cols, int mapa[][100]) {
    int ans = 0;
    int mat[100][100];
    memset(mat, 0, sizeof(mat));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            ans = max(ans, maxSlideFromPos(rows, cols, mapa, i, j, mat));
    }
    return ans;
}

int main() {
    int rows, cols, mapa[100][100];
    int tc;

    scanf("%d", &tc);
    for(int t=0; t<tc; t++) {
        char tmp[1000];
        scanf("%s%d%d", tmp, &rows, &cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                scanf("%d", &mapa[i][j]);
        printf("%s: %d\n", tmp, maxSlide(rows, cols, mapa));
    }
    
    return 0;
}
