/*
ID: me60
LANG: C++11
TASK: gift1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    map <string, int> balance;
    int n;
    string names[10000];
    cin >> n ;
    for(int i=0; i<n; i++) {
        cin >> names[i] ;
        balance[names[i]] = 0;
    }
    for(int i=0; i<n; i++) {
        string giver;
        int mon, recCount;
        cin >> giver >> mon >> recCount ;
        if(recCount==0) {
            balance[giver] += mon;
            continue;
        }
        balance[giver] += mon%recCount - mon;
        mon /= recCount;
        for(int j=0; j<recCount; j++) {
            string receiver;
            cin >> receiver;
            balance[receiver] += mon;
        }
    }

    for(int i=0; i<n; i++) {
        cout << names[i] << " " << balance[names[i]] << endl;
    }
    
    return 0;
}
