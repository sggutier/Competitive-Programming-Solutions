#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2000;
const ll inf = 1e17;

ll rows[2*limN + 10];
ll cols[2*limN + 10];
int mat[limN][limN];

int toRow(int a, int b) {
    return a+b;
}
int toCol(int a, int b) {
    return a-b+limN;
}

int main() {
    ll ans = 0;
    ll maxR[2][2] = {{-inf, -inf}, {-inf, -inf}};
    ll maxC[2][2] = {{-inf, -inf}, {-inf, -inf}};
    int N ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
            rows[toRow(i,j)] += mat[i][j];
            cols[toCol(i,j)] += mat[i][j];
        }
    }
}
