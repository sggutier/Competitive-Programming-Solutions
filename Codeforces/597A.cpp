#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b ;
    long long x,  y;
    cin >> n >> a >> b ;
    x = a/n, y = b/n;
    if(x*n < a)
        x ++;
    if(y*n > b)
        y --;
    cout << max(0LL, y-x+1) << endl;
}
