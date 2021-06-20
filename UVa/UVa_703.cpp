#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define tri pair<int, par>
#define f first
#define s second

void testCase(int N) {
    set <tri> ans;
    int mat[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if(mat[i][j] && mat[j][k] && mat[k][i]) {
                    ans.insert(tri(i, par(j, k)));
                }
                else if(!mat[i][j] && !mat[j][i] && !mat[j][k] && !mat[k][j] && !mat[i][k] && !mat[k][i]) {
                    ans.insert(tri(i, par(j, k)));
                }
            }
        }
        for(int j=0; j<i; j++) {
            for(int k=0; k<j; k++) {
                if(mat[i][j] && mat[j][k] && mat[k][i]) {
                    ans.insert(tri(i, par(j, k)));
                }
            }
        }
    }

    printf("%d\n", (int) ans.size());
    for(const auto a:ans) {
        printf("%d %d %d\n", a.f+1, a.s.f+1, a.s.s+1);
    }
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
