#include <bits/stdc++.h>
using namespace std ;
#define limN 100005

string correct_format(string S) {
    string ans;
    list <char> stream;
    list <char>::iterator pos = stream.end();
    for(int i=0, n=S.size(); i<n; i++) {
        if(S[i]=='[') 
            pos = stream.begin();
        else if(S[i]==']') 
            pos = stream.end();
        else 
            stream.insert(pos, S[i]);
    }
    ans = string(stream.size(), 'a');
    pos = stream.begin();
    for(int i=0; pos!=stream.end(); pos++, i++) {
        ans[i] = *pos;
    }
    return ans;
}

int main() {
    char tmp[limN];
    string S;

    while(fgets(tmp, limN, stdin)!=NULL) {
        S = tmp;
        S[S.size()-1] = ']';
        printf("%s\n", correct_format(S).c_str());
    }
    
    return 0;
}
