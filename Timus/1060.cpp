#include <bits/stdc++.h>
using namespace std;
const int limN = 4;
const int limB = 1<<16;
const int limK = 16;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int minP[limB];
int msks[limK];

int getMsk(int r, int c) {
    if(r < 0 || c < 0 || r>=limN || c >= limN)
        return 0;
    return 1<<(r*limN + c);
}

void printaPos(int pos, bool tabd=false) {
    for(int i=0; i<4; i++) {
        if(tabd)
            printf("\t");
        for(int j=0; j<4; j++) {
            printf("%c", (getMsk(i, j) & pos)? 'B' : 'W');
        }
        printf("\n");
    }
    printf("--------------\n");
}

int main() {
    queue <int> Q;
    int pos = 0;
    char tmp[15];
    for(int i=0; i<limN; i++) {
        for(int j=0; j<limN; j++) {
            int p = i*limN + j;
            msks[p] = getMsk(i, j);
            for(int d=0; d<4; d++)
                msks[p] |= getMsk(i + dr[d], j + dc[d]);
            // printf("el cambio en %d %d es\n", i, j);
            // printaPos(msks[p]);
        }
    }

    for(int i=0; i<limN; i++) {
        scanf("%s", tmp);
        for(int j=0; j<limN; j++) {
            if(tmp[j] == 'w') continue;
            pos += getMsk(i, j);
        }
    }

    minP[pos] = 1;
    Q.push(pos);
    // printaPos(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        int dst = minP[pos];
        // printf("pos actual tiene dst %d\n", dst);
        // printaPos(pos);
        if(pos % (limB-1) == 0) {
            printf("%d\n", dst-1);
            return 0;
        }
        for(int i=0, sg; i<limK; i++) {
            sg = pos ^ msks[i];
            if(minP[sg]) continue;
            // printf("\t Se considera a %d %d\n", i/4, i%4);
            // printaPos(sg, true);
            minP[sg] = dst+1;
            Q.push(sg);
        }
    }
    printf("Impossible\n");
}
