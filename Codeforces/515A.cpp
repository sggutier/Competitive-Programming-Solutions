#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c ;
    a = abs(a), b = abs(b);
    cout << (a+b<=c && (c-(a+b))%2==0? "Yes" : "No") << endl;
}
