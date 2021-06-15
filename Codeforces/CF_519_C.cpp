#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    int ans = 0;

    cin >> a >> b ;
    for(int i=0; 2*i<=a; i++) {
        if(i > b)
            break;
        ans = max(ans, i + min(a-2*i, (b-i)/2));
    }

    cout << ans << endl;
}
