#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    int n2 = 2*n;
    list <pair<int,int>> ans;
    for(int i=n+1; i<=n2; i++) {
        int d = __gcd(i-n, i*n);
        if(d!=i-n)
            continue;
        int y = (n*i)/d;
        ans.push_back(make_pair(y, i));
    }
    printf("%d\n", (int) ans.size());
    for(const auto &a:ans) 
        printf("1/%d = 1/%d + 1/%d\n", n, a.first, a.second);
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
