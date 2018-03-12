#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans[] = {6, 8, 4, 2};
    int n ;
    cin >> n ;
    if(n!=0)
        cout << ans[n%4] << endl;
    else
        cout << 1 << endl;
}
