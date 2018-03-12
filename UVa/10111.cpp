#include <bits/stdc++.h>
using namespace std;
const int limP = 43046721;

char brd[4][6];
//map<int,bool> dp;
bitset <limP> dp;
bitset <limP> usd;
int pots3[16];

bool hasWin(char t) {
    for(int r=0; r<4; r++) {
        bool works = true;
        for(int c=0; c<4; c++) {
            if(brd[r][c]!=t) {
                works = false;
                break;
            }
        }
        if(works)
            return true;
    }
    for(int c=0; c<4; c++) {
        bool works = true;
        for(int r=0; r<4; r++) {
            if(brd[r][c]!=t) {
                works = false;
                break;
            }
        }
        if(works)
            return true;
    }
    for(int d=-1; d<2; d+=2) {
        bool works = true;
        for(int r=0, c=(d==-1? 3 : 0); r<4; r++, c+=d) {
            if(brd[r][c]!=t) {
                works = false;
                break;
            }
        }
        if(works)
            return true;
    }
    return false;
}

bool movX(int pos);
bool movO(int pos);

void printBoard() {
    for(int i=0; i<4; i++)
        printf("%s\n", brd[i]);
}

bool movX(int pos) {
    if(usd[pos])
        return dp[pos];
    usd[pos] = true;
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            if(brd[r][c]=='.') {
                brd[r][c] = 'x';
                bool a = hasWin('x');
                if(a) {
                    brd[r][c] = '.';
                    // printBoard();
                    // printf("^ x (A) with %d %d is %d at %d\n", r, c, true, pos);
                    return dp[pos] = true;
                }
                a = movO(pos + 2*pots3[r*4 + c]);
                brd[r][c] = '.';
                if(a) {
                    // printBoard();
                    // printf("^ x (B) with %d %d is %d at %d\n", r, c, true, pos);
                    return dp[pos] = true;
                }
            }
        }
    }
    
                    // printBoard();
                    // printf("^ x (C) is %d at %d\n", false, pos);
    return dp[pos] = false;
}

bool movO(int pos) {
    if(usd[pos])
        return dp[pos];
    usd[pos] = true;
    bool any = false;
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            if(brd[r][c]=='.') {
                brd[r][c] = 'o';
                bool a = hasWin('o');
                if(a) {
                    brd[r][c] = '.';
                    // printBoard();
                    // printf("^ o (A) with %d %d is %d at %d\n", r, c, false, pos);
                    return dp[pos] = false;
                }
                a = movX(pos + pots3[r*4 + c]);
                brd[r][c] = '.';
                if(!a) {
                    // printBoard();
                    // printf("^ o (B) with %d %d is %d at %d\n", r, c, false, pos);
                    return dp[pos] = false;
                }
                any = true;
            }
        }
    }
                    // printBoard();
                    // printf("^ o (C) is %d at %d\n", any, pos);
    return dp[pos] = any;
}

void testCase() {
    int pos = 0;
    for(int i=0; i<4; i++) {
        scanf("%s", brd[i]);
        for(int j=0; j<4; j++) {
            pos += pots3[i*4 + j]*(brd[i][j]=='x'? 2 : brd[i][j]=='o');
        }
    }
    //cout << pos << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(brd[i][j]=='.') {
                brd[i][j] = 'x';
                bool a = hasWin('x') || movO(pos + 2*pots3[i*4 + j]);
                brd[i][j] = '.';
                if(a) {
                    printf("(%d,%d)\n", i, j);
                    return;
                }
            }
        }
    }
    printf("#####\n");
}

int main() {
    pots3[0] = 1;
    for(int i=1; i<16; i++)
        pots3[i] = pots3[i-1]*3;
    char tmp[5];
    while(scanf("%s", tmp)!=EOF && tmp[0]=='?')
        testCase();
}
