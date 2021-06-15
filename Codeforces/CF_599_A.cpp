#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c ;
    cout << min(a, b+c) + min(b, a+c) + min(c, a+b) << endl;
}
