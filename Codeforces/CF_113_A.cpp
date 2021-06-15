#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

string suffs[] = {"lios", "liala", "etr", "etra", "initis", "inites"};

bool isSuff(string &a, string &b) {
    return a.size() <= b.size() && b.substr(b.size()-a.size(), a.size()) == a;
}

int toNum(string a) {
    for(int i=0; i<6; i++)
        if(isSuff(suffs[i], a))
            return i;
    return 7;
}

int main() {
    vector <int> wds;
    char tmp[limN];
    bool funca = true;
    int nn = 0;

    while(scanf("%s", tmp)!=EOF) {
        int w = toNum(tmp);
        if(w==7) {
            printf("NO\n");
            return 0;
        }
        wds.push_back(w);
    }

    if((int) wds.size()==1) {
        printf("YES\n");
        return 0;
    }

    for(int i=0; i<(int) wds.size(); i++) {
        if(i)
            funca &= (wds[i]%2 == wds[i-1]%2) && (wds[i]/2 >= wds[i-1]/2);
        if(wds[i]/2==1)
            nn ++;
    }

    funca &= nn==1;

    printf("%s\n", funca? "YES" : "NO");
}
