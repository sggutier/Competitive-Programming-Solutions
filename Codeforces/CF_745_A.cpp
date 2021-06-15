#include <bits/stdc++.h>
using namespace std;

int main() {
    set <string> ans;
    string s;

    cin >> s ;

    for(int i=s.size(); i; i--) {
        ans.insert(s);
        s = s.substr(1, s.size()-1) + s.substr(0, 1);
    }

    cout << ans.size() << endl;
}
