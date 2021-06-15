#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    pair<int,int> ans(1e9, 0);
    scanf("%d", &n);
    for(int i=0; 4*i<=n; i++) {
        if( (n-4*i) % 7 == 0)
            ans = min(ans, {i + (n-4*i)/7, (n-4*i)/7});
    }

    if(ans.first == 1e9)
        printf("-1\n");
    else {
        for(int kv = ans.first - ans.second; kv>0; kv--)
            printf("4");
        for(int kv = ans.second; kv>0; kv--)
            printf("7");
        printf("\n");
    }
}
