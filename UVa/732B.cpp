#include <bits/stdc++.h>
using namespace std;

int main() {
    int u = 1e9;
    int n, k;
    vector <int> ans;
    int sumo = 0;

    cin >> n >> k ;
    for(int i=0; i<n; i++) {
        int a ;
        cin >> a ;
        if(a+u < k) {
            sumo += k-(a+u);
            a += k-(a+u);            
        }
        ans.push_back(a);
        u = a;
    }

    cout << sumo << endl;
    for(int a:ans)
        cout << a << " " ;
    cout << endl;
}
