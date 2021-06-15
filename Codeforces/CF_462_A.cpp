#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int N ;
char mapa[105][105];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%s", mapa[i] + 1);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int cnt = 0;
            for(int d=0; d<4; d++) {
                int r = i + dr[d], c = j + dc[d];
                if(mapa[r][c]=='o')
                    cnt ++;
            }
            if(cnt%2) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
}
