#include <bits/stdc++.h>
using namespace std;

int calcTim(int s, int v, int t) {
    return s*v + 2*t;
}

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int tot1 = calcTim(s, v1, t1);
    int tot2 = calcTim(s, v2, t2);
    string ans;
    if(tot1 == tot2) ans = "Friendship";
    else ans = tot1 < tot2? "First" : "Second";
    cout << ans << endl;
}
