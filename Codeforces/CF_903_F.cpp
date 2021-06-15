#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int LIM_B = (1 << 16) + 5;
const int LIM_BD = (1 << 12);
const int LIM_N = 1015;
const int INF = 1e8 ;

int csts[7];
vector<pii> trans;
char lins[4][LIM_N];
int _cur[LIM_BD + 5], _nxt[LIM_BD + 5];

void printMsk(const int msk) {
    for(int c=0; c < 4; c++) {
        for(int r=3; r >= 0; r--) {
            printf("%c", ((1 << (r * 4 + c)) & msk)? '*' : '.');
        }
        printf("\n");
    }
}

void bruta(const int pos = 0, const int msk = 0, const int sm = 0, const int ult = 0) {
    if(ult >= 4) {
        trans.push_back({sm, msk});
        // for(int b=(1 << 16) - 1, x; b >= 0; b--) {
        //     x = (msk | b) ^ msk;
        //     if(x < LIM_BD)
        //         trans[b].push_back({sm, x});
        // }
        return ;
    }
    bruta(pos+1, msk, sm, max(ult, pos + 1));
    for(int i=1; i <= 4; i++) {
        if(pos + i < ult)
            continue;
        int df = 0 ;
        for(int j=0; j < i && pos + j < 4; j++) {
            for(int k=0; k < i; k++) {
                df |= 1 << ((3 - k) * 4 + (pos+j));
            }
        }
        bruta(pos + 1, msk | df, sm + csts[i], pos + i);
    }
}

int main() {
    int C ;
    scanf("%d", &C);
    for(int i=1; i <= 4; i++) {
        scanf("%d", &csts[i]);
    }
    bruta();
    for(int i=0; i < 4; i++) {
        scanf("%s", lins[i]);
    }
    C += 4;
    int *cur = _cur, *nxt = _nxt;
    fill(cur, cur + LIM_BD, INF);
    cur[0] = 0 ;
    for(int c=0; c < C; c++, swap(cur, nxt)) {
        fill(nxt, nxt + LIM_BD, INF);
        int ult = 0 ;
        for(int r=0; r < 4; r++)
            if(lins[r][c] == '*')
                ult |= 1 << r ;
        for(int b=(1 << 12) - 1, w, x; b >= 0; b--) {
            int cst = cur[b];
            w = (b << 4) | ult;
            for(const auto &e : trans) {
                x = (e.second | w) ^ e.second;
                if(x < LIM_BD)
                    nxt[x] = min(nxt[x], cst + e.first);
            }
        }
    }
    printf("%d\n", cur[0]);
}
