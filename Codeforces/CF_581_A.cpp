#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b ;
    int x, y;
    cin >> a >> b ;
    x = min(a, b);
    y = max((a-x)/2, (b-x)/2);
    cout << x << " " << y << endl;
}
