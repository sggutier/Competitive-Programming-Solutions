#include <bits/stdc++.h>
using namespace std;

void testCase(int n, int m, int t) {
    pair<int,int> ans = make_pair(-(1<<30), 0) ;
    int a = 0;
    for(int i=0; i<=t; i+=n, a++) {
        ans = max(ans, make_pair(-(t-i)%m, a + (t-i)/m));
    }
    if(ans.first)
        printf("%d %d\n", ans.second, -ans.first);
    else
        printf("%d\n", ans.second);
}

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF)
        testCase(a,b,c);
}
