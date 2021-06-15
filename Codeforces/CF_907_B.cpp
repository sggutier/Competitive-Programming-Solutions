#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char mp[15][15];

bool blockFull(int r, int c) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if(mp[r*3 + i][c*3 + j] == '.') {
                return false;
            }
        }
    }
    return true;
}

void fillBlock(int r, int c) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if(mp[r*3 + i][c*3 + j] == '.')
                mp[r*3 + i][c*3 + j] = '!';
        }
    }
}

int main() {
    for(int i=0; i < 9; i++) {
        for(int j=0; j < 9; j += 3)
            scanf("%s", mp[i] + j);
    }
    int x, y ;
    scanf("%d%d", &x, &y);
    x--, y--;
    if(blockFull(x%3, y%3)) {
        for(int i=0; i < 3; i++)
            for(int j=0; j < 3; j++)
                fillBlock(i, j);
    }
    else {
        fillBlock(x%3, y%3);
    }
    for(int i=0; i < 9; i++) {
        if(i && i%3 == 0) {
            putchar('\n');
        }
        for(int j=0; j < 9; j++) {
            if(j && j%3 == 0) {
                putchar(' ');
            }
            putchar(mp[i][j]);
        }
        putchar('\n');
    }
}
