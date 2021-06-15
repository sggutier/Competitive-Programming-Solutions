#include <bits/stdc++.h>
using namespace std;

int revs[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int revT(int t) {
    if(revs[t%10] == -1 || revs[t/10] == -1)
        return -1;
    return 10*revs[t%10] + revs[t/10];
}

bool revable(int H, int M, int h, int m) {
    int x = revT(m), y = revT(h);
    return x != -1 && x < H && y != -1 && y < M;
}

void testCase() {
    int H, M ;
    int h, m ;
    scanf("%d%d", &H, &M);
    scanf("%d:%d", &h, &m);
    while(!revable(H, M, h, m)) {
        m = (m+1) % M;
        if(m == 0)
            h = (h+1) % H;
    }
    printf("%02d:%02d\n", h, m);
}

int main() {
    int t;
    for(scanf("%d", &t); t; t--)
        testCase();
}
