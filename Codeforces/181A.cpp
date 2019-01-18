#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int R, C ;
char matr[limN][limN];

int main() {
    vector <int> rs, cs;

    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++) {
        scanf("%s", matr[i]);
        for(int j=0;j<C; j++) {
            if(matr[i][j] == '*')
                rs.push_back(i), cs.push_back(j);
        }
    }

    for(const int r: rs )
        for(const int c : cs) {
            if(matr[r][c] == '.')  {
                printf("%d %d\n", r+1, c+1);
                return 0 ;
            }
        }
}
