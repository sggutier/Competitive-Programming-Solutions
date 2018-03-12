#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    if(n<=1) {
        printf("%d\n", n);
        return;
    }
    vector <int> ans ;
    for(int i=9; i>1; i--) {
        while(n%i==0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if(n>1) {
        printf("-1\n");
        return;
    }
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    printf("\n");
}

int main() {
    int tc, n;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        testCase(n);
    }
}
