#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limD = 7;
const int dr[] = {-1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 1, -1, 1, -1, 0, 1};

void makeKMPTable(int n, char *s, int *ant) {
    ant[0] = -1;
    int i=-1, j=0;
    while(j<n) {
        while(i!=-1 && s[i]!=s[j])
            i = ant[i];
        i++, j++;
        ant[j] = i;
    }
}

void findWord(int N, char mat[][limN], char *word) {
    int k = strlen(word);
    int ant[limN];
    makeKMPTable(k, word, ant);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int d=0; d<limD; d++) {
                if(0<=i-dr[d] && i-dr[d]<N && 0<=j-dc[d] && j-dc[d]<N)
                    continue;
                int pos = 0;
                for(int x=i, y=j; 0<=x && x<N && 0<=y && y<N; x+=dr[d], y+=dc[d]) {
                    while(pos!=-1 && word[pos]!=mat[x][y])
                        pos = ant[pos];
                    pos++;
                    if(pos==k) {
                        printf("%d,%d %d,%d\n", x-(k-1)*dr[d]+1, y-(k-1)*dc[d]+1, x+1, y+1);
                        return;
                    }
                }
            }
        }
    }
    printf("Not found\n");
}

void testCase(int N) {
    char mat[limN][limN];
    char tmp[limN];
    for(int i=0; i<N; i++)
        gets(mat[i]);
    while(gets(tmp) && tmp[0]!='0') {
        findWord(N, mat, tmp);
    }
}

int main() {
    char tmp[500];
    while(gets(tmp)) {
        testCase(atoi(tmp));
        break;
    }
}
