#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 2;

int N;
int mat[limN][limN];

bool homo() {
    bool ans = true;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
            if( i && j)
                ans &= (mat[i][j] + mat[i-1][j-1] == mat[i-1][j] + mat[i][j-1]);
        }
    }
    return ans;
}

int main() {
    while(scanf("%d", &N)!=EOF && N)
        printf("%shomogeneous\n", !homo()? "not " : "");
}
    
