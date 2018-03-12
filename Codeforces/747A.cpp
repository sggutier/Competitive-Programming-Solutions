#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    pair <int, int> ans(1e9, 0);

    cin >> N ;
    for(int i=1; i*i<=N; i++) {
        if(N%i)
            continue;
        ans = min(ans, {N/i -i, i});
    }

    printf("%d %d\n", ans.second, ans.first + ans.second);
}
