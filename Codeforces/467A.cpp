#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    int ans = 0;
    cin >> n ;
    while(n--)
        {
            int a, b ;
            cin >> a >> b ;
            if(a+2 <= b)
                ans ++;
        }
    cout << ans << endl;
}
