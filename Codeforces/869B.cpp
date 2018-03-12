#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    __int128 ans = 1;
    cin >> a >> b;
    for(int i=1; i<=10 && a+i<=b; i++)
        ans = (ans*(a+i))%10;
    cout << ((long long) ans) << endl;
}
