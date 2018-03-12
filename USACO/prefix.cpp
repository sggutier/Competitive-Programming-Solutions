/*
ID: me60
LANG: C++11
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    
    vector <string> primitives;
    string S = "";
    int ans = 0;
    bool possible[200005];
    char tmp[200005];

    while(scanf("%s", tmp)!=EOF && tmp[0]!='.')
        primitives.push_back(tmp);
    memset(possible, 0, sizeof(possible));
    possible[0] = true;
    while(scanf("%s", tmp)!=EOF) {
        S += tmp;
    }

    for(int i=1; i<=(int) S.size(); i++) {
        for(string p: primitives) {
            if((int) p.size()>i)
                continue;
            // printf("%d %s %s\n", possible[i-p.size()], S.substr(i-p.size(), p.size()).c_str(), p.c_str());
            if(possible[i-p.size()] && S.substr(i-p.size(), p.size())==p) {
                possible[i] = true;
                break;
            }
        }
        if(possible[i])
            ans = i;
        // printf("%d -> %d %c\n", i, possible[i], S[i-1]);
    }

    printf("%d\n", ans);

    return 0;
}
