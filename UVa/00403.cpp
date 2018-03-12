#include <bits/stdc++.h>
using namespace std;
const int limN = 60;

string lins[5][27] = {
    {".***..",  "****..",  ".****.",  "****..",  "*****.",  "*****.",  ".****.",  "*...*.",  "*****.",     "..***.",  "*...*.",  "*.....",  "*...*.",  "*...*.",  ".***..",  "****..",  ".***..",  "****..",     ".****.",  "*****.",  "*...*.",  "*...*.",  "*...*.",  "*...*.",  "*...*.",  "*****.",  "......"},
    {"*...*.",  "*...*.",  "*...*.",  "*...*.",  "*.....",  "*.....",  "*.....",  "*...*.",  "..*...",     "...*..",  "*..*..",  "*.....",  "**.**.",  "**..*.",  "*...*.",  "*...*.",  "*...*.",  "*...*.",     "*.....",  "*.*.*.",  "*...*.",  "*...*.",  "*...*.",  ".*.*..",  ".*.*..",  "...*..",  "......"},
    {"*****.",  "****..",  "*.....",  "*...*.",  "***...",  "***...",  "*..**.",  "*****.",  "..*...",     "...*..",  "***...",  "*.....",  "*.*.*.",  "*.*.*.",  "*...*.",  "****..",  "*...*.",  "****..",     ".***..",  "..*...",  "*...*.",  ".*.*..",  "*.*.*.",  "..*...",  "..*...",  "..*...",  "......"},
    {"*...*.",  "*...*.",  "*.....",  "*...*.",  "*.....",  "*.....",  "*...*.",  "*...*.",  "..*...",     "*..*..",  "*..*..",  "*.....",  "*...*.",  "*..**.",  "*...*.",  "*.....",  "*..**.",  "*..*..",     "....*.",  "..*...",  "*...*.",  ".*.*..",  "**.**.",  ".*.*..",  "..*...",  ".*....",  "......"},
    {"*...*.",  "****..",  ".****.",  "****..",  "*****.",  "*.....",  ".***..",  "*...*.",  "*****.",     ".**...",  "*...*.",  "*****.",  "*...*.",  "*...*.",  ".***..",  "*.....",  ".****.",  "*...*.",     "****..",  ".***..",  ".***..",  "..*...",  "*...*.",  "*...*.",  "..*...",  "*****.",  "......"}};

char ans[limN][limN+10];

void printP() {
    // printf("La página es:\n");
    for(int i=0; i<limN; i++)
        printf("%s\n", ans[i]);
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("\n");
}

void pbc(int r, int c, char s) {
    int p = s!=' '? s- 'A' : 26;
    for(int i=0; i<5; i++) {
        if(r+i >= limN || r+i<0)
            continue;
        for(int j=0; j<6; j++) {
            if(c+j >= limN || c+j<0)
                continue;
            // printf("Intentantdo printar %c en %d %d\n", s, r+i, c+j);
            if(lins[i][p][j]=='*')
                ans[r+i][c+j] = lins[i][p][j] ;
        }
    }
}

void psc(int r, int c, char s) {
    if(0 <= r && r < limN && 0 <= c && c < limN && s!=' ')
        ans[r][c] = s;
}

function<void(int, int, char)> fcs[] = {psc, pbc};

void pline(int r, int c, int N, char *s, int tp) {
    int stp = 1 + tp*5;
    for(int i=0; i<N; i++) {
        fcs[tp](r, c+i*stp, s[i]);
    }
}

void lline(int r, int c, int N, char *s, int tp) {
    int stp = 1 + tp*5;
    for(int i=0; i<N; i++) {
        fcs[tp](r, i*stp, s[i]);
    }
}

void rline(int r, int c, int N, char *s, int tp) {
    int stp = 1 + tp*5;
    for(int i=0; i<N; i++) {
        fcs[tp](r, limN-(i+1)*stp, s[N-1-i]);
    }
}

void cline(int r, int c, int N, char *s, int tp) {
    int stp = 1 + tp*5;
    int tot = stp*N;
    // if(tot >= limN) {
    //     /c = (tot-limN)/2;
    //     lline(r, c, N, s, tp);
    //     return;
    // }
    c = (limN-tot)/2 + tot%2;
    pline(r, c, N, s, tp);
}

map<char, function<void(int, int, int, char*, int)>> pts;

int main() {
    for(int i=0; i<limN; i++)
        for(int j=0; j<limN; j++)
            ans[i][j] = '.';
    pts['P'] = pline;
    pts['L'] = lline;
    pts['R'] = rline;
    pts['C'] = cline;
    char tmp[5];
    int tp;
    int W = 0;
    char msg[300];
    int ren, col=0;
    while(scanf("%s", tmp)!=EOF) {
        if(tmp[1]=='E') {
            printP();
            for(int i=0; i<limN; i++)
                for(int j=0; j<limN; j++)
                    ans[i][j] = '.';
            continue;
        }
        tp = tmp[1];
        scanf("%s%d", tmp, &ren);
        if(tp=='P')
            scanf("%d", &col);
        ren--, col--;
        while(scanf("%c", &msg[0])!=EOF && msg[0]!='|');
        for(W=0; scanf("%c", &msg[W])!=EOF && msg[W]!='|'; W++);
        msg[W] = 0;
        pts[tp](ren, col, W, msg, tmp[1]=='1'? 0 : 1);
        // printP();
    }    
}
