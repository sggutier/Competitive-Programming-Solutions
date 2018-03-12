#include <bits/stdc++.h>
using namespace std;

int testCase(char* str, int k) {
    int n = strlen(str);
    int crg = 0, ans = 0;

    for(int i=0; i<n; i++) {
        // cout << str << " " << crg << endl;
        if(str[i]=='-')
            crg ++;
        if(i-k+1<0 || str[i-k+1]=='+')
            continue ;
        ans ++;
        crg = k - crg;
        for(int j = i-k+1; j<=i; j++)
            str[j] = str[j]=='+'? '-' : '+' ;
    }

    if(crg>0)
        return -1 ;
    return ans;
}

int main() {
    int tc;
    char str[150000];
    int n;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%s%d", str, &n);
        int ans = testCase(str, n);
        printf("Case #%d: ", i);
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    
    return 0;
}
