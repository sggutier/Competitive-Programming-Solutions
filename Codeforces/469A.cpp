#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, k;
    vector <int> usd;

    cin >> N ;
    usd.resize(N+1);
    for(int w=0; w<2; w++) {
        cin >> k ;
        for(int i=0; i<k; i++) {
            int a ;
            cin >> a ;
            usd[a] = true;
        }
    }

    for(int i=1; i<=N; i++) {
        if(!usd[i]) {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }

    cout << "I become the guy." << endl;
}
