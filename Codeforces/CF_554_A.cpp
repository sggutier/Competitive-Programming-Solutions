#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set <string> ans;
    char stro[] = "a";

    cin >> s;
    for(int i=0; i<=(int) s.size(); i++) {
        stro[0] = 'a';
        for(char *c=stro; *c<='z'; (*c)++)
            ans.insert(s.substr(0,i) + string(stro) +s.substr(i, s.size()-i) );
    }

    cout << ans.size() << endl;
}
