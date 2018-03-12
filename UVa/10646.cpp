#include <bits/stdc++.h>
using namespace std;
const int limP = 27;
const int limH = 25;

int val(string &s) {
    return isdigit(s[0])? s[0]-'0' : 10;
}

void testCase() {
    string pile[limP];
    string hand[limH];
    int pos = limP-1;
    //int pos = 0;
    int Y = 0;

    
        //for(int i=limP-1; i>=0; i--)
    for(int i=0; i<limP; i++)
        cin >> pile[i];
    for(int i=0; i<limH; i++)
    //for(int i=limH-1; i>=0; i--)
        cin >> hand[i];

    for(int i=0; i<3; i++) {
        //cout << "removing " << pile[pos] << " with val: " << val(pile[pos]) << endl;
        int x = val(pile[pos]);
        Y += x;
        pos -= (10 - x)+1;
    }
    //cout << pos << endl;

    //cout << Y << endl;
    Y -- ;
    if(Y <= pos)
        cout << pile[pos] << endl;
    else
        cout << hand[Y-(pos+1)] << endl;
}

int main() {
    int tc;
    cin >> tc;
    for(int i=1; i<=tc; i++) {
        cout << "Case " << i << ": " ;
        //cout << endl;
        testCase();
    }
}
