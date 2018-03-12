#include <bits/stdc++.h>
using namespace std;

int ans[105];

int testCase(int n) {
    if(ans[n])
        return ans[n];
    int a = 0;
    for(int i=1; i<=n; i++) 
        a += (n-i+1)*(n-i+1);
    return ans[n] = a;
}

int main() {
    int tc;

    while(scanf("%d", &tc)!=EOF && tc!=0) {
        printf("%d\n", testCase(tc));
    }
    
    return 0 ;
}
