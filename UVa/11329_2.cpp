#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
const int N = 4;
const int limB = 1<<16;

map <int, int> minP[N][N][limB];
int movs[limB][N];

void llena(const int pos, const int msk, int *arr) {
    if(pos==-1) {
        movs[msk][0] = (arr[4]<<0) + (arr[1]<<1) + (arr[5]<<2) + (arr[3]<<3) + (arr[2]<<4) + (arr[0]<<5);        
        movs[msk][3] = (arr[1]<<0) + (arr[2]<<1) + (arr[3]<<2) + (arr[0]<<3) + (arr[4]<<4) + (arr[5]<<5);
        movs[msk][2] = (arr[5]<<0) + (arr[1]<<1) + (arr[4]<<2) + (arr[3]<<3) + (arr[0]<<4) + (arr[2]<<5);
        movs[msk][1] = (arr[3]<<0) + (arr[0]<<1) + (arr[1]<<2) + (arr[2]<<3) + (arr[4]<<4) + (arr[5]<<5);
        return;
    }
    arr[pos] = 0;
    llena(pos-1, msk, arr);
    arr[pos] = 1;
    llena(pos-1, msk | (1<<pos), arr);
}

void precarga() {
    int arr[6];
    llena(5, 0, arr);
}

void printDice(int msk) {
    for(int i=0; i<6; i++)
        printf("%d ", (1<<i) & msk? 1 : 0);
    printf("\n");
}

void printBoard(int msk) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%c", msk & (1<<(i*N+j))? 'X' : '.');
        printf("\n");
    }
}

int bfs(int r, int c, int msk) {
    queue <int> qR, qC, qD, qB;
    int d, b, dst;
    qR.push(r); qC.push(c); qD.push(0); qB.push(msk);
    //cout << msk << endl;
    minP[r][c][msk][0] = 0;
    while(!qR.empty()) {
        r = qR.front(); qR.pop();
        c = qC.front(); qC.pop();
        d = qD.front(); qD.pop();
        b = qB.front(); qB.pop();
        // printf("[[ %d ]]\n", minP[r][c][d][b]);
        // printf("%d %d => ", r, c);
        // printDice(d);
        // printBoard(b);
        // getchar();
        dst = minP[r][c][b][d];
        if(b==0)
            return dst;
        for(int k=0; k<4; k++) {
            int x=r+dr[k], y=c+dc[k];
            if(x < 0 || x>=N || y<0 || y>=N)
                continue;
            int d2 = movs[d][k], b2 = b;
            // printf("\t%d %d => ", x, y);
            // printDice(d2);
            if( (d2&1) ^ (((1<<(x*N + y)) & b) != 0)  ) {
                //printf("\tcambio\n");
                d2 ^= 1;
                b2 ^= (1<<(x*N + y));
            }
            if(minP[x][y][b2].count(d2))
                continue;
            minP[x][y][b2][d2] = dst + 1;
            qR.push(x);
            qC.push(y);
            qD.push(d2);
            qB.push(b2);
        }
    }
    return -1;
}

void testCase() {
    char mat[N][N+3];
    int msk = 0;
    int x=0, y=0;
    for(int i=0; i<N; i++) {
        scanf("%s", mat[i]);
        for(int j=0; j<N; j++) {
            if(mat[i][j]=='X')
                msk |= (1<<(i*N + j));
            else if(mat[i][j]=='D')
                x=i, y=j;
            for(int b=0; b<limB; b++)
                minP[i][j][b].clear();
        }
    }
    //printf("Staruto\n");
    int ans = bfs(x, y, msk);
    if(ans==-1)
        printf("impossible\n");
    else
        printf("%d\n", ans);
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
