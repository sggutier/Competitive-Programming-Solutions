#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

char mat[limN];

int main() {
    int N, M ;

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", mat);
        for(int j=0; j<M; j++) {
            if(mat[j]=='-')
                continue;
            mat[j] = (i+j)%2? 'B' : 'W';
        }
        printf("%s\n", mat);
    }
}
