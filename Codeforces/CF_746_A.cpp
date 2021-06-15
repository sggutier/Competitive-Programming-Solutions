#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c ;
    cout << 7 * min(c/4, min(b/2, a)) << endl;
}
