#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int minP[limN][limN][limN];

int main() {
    int N, pos, l, r;
    int ans = 0;
    scanf("%d%d%d%d", &N, &pos, &l, &r);
    queue <int> ql, qp, qr;
    ql.push(1);
    qp.push(pos);
    qr.push(N);
    minP[1][pos][N] = 1;
    while(!ql.empty()) {
        int a=ql.front(), b=qr.front(), i = qp.front();
        ql.pop(), qr.pop(), qp.pop();
        int d = minP[a][i][b];
        //printf("%d %d %d => %d\n", a,i,b, d-1);
        if(a==l && b==r) {
            printf("%d\n", d-1);
            return 0;
        }
        d++;
        if(!minP[a][max(i-1, a)][b]) {
            ql.push(a), qp.push(max(i-1, a)), qr.push(b);
            minP[a][max(i-1, a)][b] = d;
        }
        if(!minP[a][min(i+1, b)][b]) {
            ql.push(a), qp.push(min(i+1, b)), qr.push(b);
            minP[a][min(i+1, b)][b] = d;
        }
        if(!minP[i][i][b]) {
            ql.push(i), qp.push(i), qr.push(b);
            minP[i][i][b] = d;
        }
        if(!minP[a][i][i]) {
            ql.push(a), qp.push(i), qr.push(i);
            minP[a][i][i] = d;
        }
    }
}
