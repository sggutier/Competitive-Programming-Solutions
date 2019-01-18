#include <bits/stdc++.h>
using namespace std;

int main() {
    int W ;
    cin >> W ;
    for(; W; W--) {
        int a, b, d;
        cin >> a >> b >> d ;
        long long c = b/d;
        if(d < a)
            cout << d << endl;
        else
            cout << d*(c+1) << endl;
    }
}
