#include <bits/stdc++.h>
using namespace std;

bool testCase(char *s) {
    vector<string> noms;

    do{
        noms.push_back(s);
    }while(scanf("%s", s)!=EOF && s[0]!='9');

    for(int i=noms.size()-1; i>=0; i--) {
        for(int j=noms.size()-1; j>=0; j--) {
            if(i==j)
                continue;
            if(noms[i].size() <= noms[j].size() && noms[j].substr(0, noms[i].size())==noms[i])
                return false;
        }
    }
    return true;
}

int main() {
    int tc = 0;
    char S[5000];
    while(scanf("%s", S)!=EOF) {
        printf("Set %d is %simmediately decodable\n", ++tc, testCase(S)? "" : "not ");
    }
}
