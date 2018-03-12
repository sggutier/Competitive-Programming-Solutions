#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, 0, 1, 1, 0};
const int dy[] = {1, 0, -1, -1, 0, 1};
const int limD = 6;

void testCase(int K) {
    if(K==1) {
        printf("0 0\n");
        return;
    }
    int n = 0, sum=1;
    while(sum<K) {
        n++;
        sum += n*6;
    }
    sum -= n*6;
    //printf("=> %d %d (%d)\n", n, sum, K);
    K -= sum;
    int x = n, y=0;
    for(int d=0; K; d++) {
        for(int i=0; i<n && K; K--, i++) {
            x += dx[d];
            y += dy[d];
        }
    }
    printf("%d %d\n", x, y);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
        testCase(n);
}
