#include <bits/stdc++.h>
using namespace std;

void testCase(char *str) {
    int n = strlen(str);
    vector <vector<long long>> ans(n, vector<long long>(n, 0));
     for(int i=0; i<n; i++)
         ans[i][i] = 1LL;
    // for(int i=1; i<n; i++)
    //     ans[i-1][i] = (str[i-1]==str[i]);
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            ans[j][i] = ans[j+1][i-1];
            ans[j][i] += 2LL;
            if(str[j]==str[i]) {
                ans[j][i] += 1LL + ans[j+1][i-1];
            }
            for(int k=j+1; k<i; k++) {
                if(str[j] == str[k]) {
                    ans[j][i] += 1LL + ans[j+1][k-1];
                }
            }
            for(int k=i-1; k>j; k--) {
                if(str[i] == str[k]) {
                    ans[j][i] += 1LL + ans[k+1][i-1];
                }
            }
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         printf("%2lld ", ans[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n", ans[0][n-1]);
}

int main() {
    int tc;
    char str[65];

    for(scanf("%d", &tc); tc; tc--) {
        scanf("%s", str);
        testCase(str);
    }
    
    return 0;
}
