#include <bits/stdc++.h>
using namespace std;
const int limN = 55;

int main() {
    int N ;
    int mat[limN][limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            scanf("%d", &mat[i][j]);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(mat[i][j] == 1)
                continue;
            bool works = false;
            for(int a=0; a<N && !works; a++) {
                for(int b=0; b<N && !works; b++) {
                    if(mat[i][a] + mat[b][j] == mat[i][j])
                        works = true;
                }
            }
            if(!works) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
}
