#include <bits/stdc++.h>
using namespace std;
const int limN = 10;

int ans[limN+1];

void precarga() {
    ans[0] = ans[1] = 1;
    for(int i=2; i<=limN; i++)
        for(int j=0; j<i; j++)
            ans[i] += ans[j] * ans[i-1-j];
}

int main() {
    precarga();

    int n;
    int tc ;
    
    while(scanf("%d", &n)!=EOF) {
        if(tc++)
            printf("\n");
        printf("%d\n", ans[n]);
    }
    
    return 0;
}
