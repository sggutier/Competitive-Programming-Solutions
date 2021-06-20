#include <bits/stdc++.h>
using namespace std;

bool testCase(int n) {
    int tmp, ans=0;
    while(n--) {
        scanf("%d", &tmp);
        ans ^= tmp;
    }
    return ans!=0;
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF && n)
        printf("%s\n", testCase(n)? "Yes" : "No");
    
    return 0;
}
