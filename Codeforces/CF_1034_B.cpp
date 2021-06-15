#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pans(ll r, ll c) {
    if(r%2 && c%2)
        return pans(r, c-1) + r/2;
    if(r%2)
        swap(r, c);
    return (r/2) * c;
}

int main() {
	ll r, c;
    cin >> r >> c ;
    if(r > c)
        swap(r, c);
    if(r + c <= 4) {
        cout << 0 << endl;
        return 0;
    }
    if(r==1) {
        if(c%6 <= 3)
            cout << c - c%6;
        else if(c%6 == 5)
            cout << c - 1 ;
        else if(c%6 == 4)
            cout << c-2 ;
        cout << endl;
        return 0;
    }

    if(r==2 && c==7) {
        cout << 12 << endl;
        return 0;
    }
    else if(r==2 && c==3) {
        cout << 4 << endl;
        return 0;
    }

    cout << pans(r, c)*2 << endl;
}
