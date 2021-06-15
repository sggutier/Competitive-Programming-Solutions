#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
const int inf = 1e9;

map <par, int> minPMemo;

int memo(int a, int b) {
    if(a==b)
        return 0;
    if(!a || !b)
        return inf;
    if(minPMemo.count({a,b}))
        return minPMemo[{a,b}];
    int ans = inf;
    if(a%2==0)
        ans = min(ans, 1 + memo(a/2, b));
    if(a%3==0)
        ans = min(ans, 1 + memo(a/3, b));
    if(a%5==0)
        ans = min(ans, 1 + memo(a/5, b));
    if(b%2==0)
        ans = min(ans, 1 + memo(a, b/2));
    if(b%3==0)
        ans = min(ans, 1 + memo(a, b/3));
    if(b%5==0)
        ans = min(ans, 1 + memo(a, b/5));
    return minPMemo[{a,b}] = ans;
}

int main() {
    int a, b ;
    scanf("%d%d", &a, &b);
    int ans = memo(a,b);
    printf("%d\n", ans==inf? -1 : ans);
}
