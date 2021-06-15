#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m ;
    if(n==1)
        cout << 1 << endl;
    else
        cout << (m<=n/2? m+1 : m-1) << endl;
}
