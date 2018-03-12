#include <bits/stdc++.h>
using namespace std;

int ans[31][4];
int conto[31];

void precarga() {
    ans[0][0] = 1;
    for(int i=1; i<=30; i++) {
        for(int j=0; j<=2; j++)
            ans[i][0] += ans[i-1][j];
        for(int j=1; j<=2; j++)
            ans[i][j] = ans[i-1][j-1];
        conto[i] = (1<<i) - (ans[i][0] + ans[i][1] + ans[i][2]);
    }
}

int main() {
    precarga();
    
    int n;

    while(scanf("%d", &n)!=EOF && n)
        printf("%d\n", conto[n]);
}
