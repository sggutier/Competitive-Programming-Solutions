#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, k;
    deque <int> Q;
    cin >> N >> k;
    for(int i=0, a; i<N; i++) {
        cin >> a;
        Q.push_back(a);
    }
    int ans = 0;
    while(!Q.empty() && Q.back() <= k) {
        Q.pop_back();
        ans ++;
    }
    while(!Q.empty() && Q.front() <= k) {
        Q.pop_front();
        ans ++;
    }
    printf("%d\n", ans);
}
