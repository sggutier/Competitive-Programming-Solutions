#include <bits/stdc++.h>
using namespace std;
const int N = 50;

char ans[N][N + 5];

void ponC(int r, int c, int k, char o, char t) {
    for(int i=0; i<25; i++) {
        for(int j=0; j<25; j++) {
            ans[i+r][j+c] = o;
            if(i%2 || j%2 || k==0 || i==24 || j==24)
                continue;
            ans[i+r][j+c] = t;
            k--;
        }
    }
}

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ponC(0, 0, b-1, 'A', 'B');
    ponC(0, 25, c-1, 'B', 'C');
    ponC(25, 0, d-1, 'C', 'D');
    ponC(25, 25, a-1, 'D', 'A');
    printf("50 50\n");
    for(int i=0; i<N; i++)
        printf("%s\n", ans[i]);
}
