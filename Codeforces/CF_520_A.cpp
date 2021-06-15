#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    string s;
    set <int> apprs;

    cin >> N >> s;
    for(const char &c:s)
        apprs.insert(tolower(c));

    for(int i='a'; i<='z'; i++)
        if(apprs.count(i) == 0) {
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
}
