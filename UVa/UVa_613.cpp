#include <bits/stdc++.h>
using namespace std;

string shift(string S) {
    vector <int> cnt(10);
    string ans = "";
    for(int i=S.size()-1; i>=0; i--)
        cnt[S[i] - '0']++;
    for(int i=9; i>=0; i--) {
        if(!cnt[i])
            continue;
        int k = cnt[i];
        ans += (i + '0');
        while(k) {
            ans += (k%10 + '0');
            k /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void testCase(string S) {
    map <string, int> prevs ;

    prevs[S] = 0;
    int stp = 1;
    string nxt = shift(S);
    if(S==nxt) {
        printf("%s is self-inventorying\n", S.c_str());
        return;
    }
    // cout << S << endl;
    while(stp<=15 && prevs.count(nxt)==0) {
        prevs[nxt] = stp;
        stp ++;
        nxt = shift(nxt);
    }
    if(stp>15) { 
        printf("%s can not be classified after 15 iterations\n", S.c_str());
        return;
    }
    int ant = prevs[nxt];
    if(stp-ant==1)
        printf("%s is self-inventorying after %d steps\n", S.c_str(), stp-1);
    else if(prevs.count(nxt))
        printf("%s enters an inventory loop of length %d\n", S.c_str(), stp - prevs[nxt]);
}

int main() {
    while(true) {
        char tmp[1000];
        scanf("%s", tmp);
        if(tmp[0]=='-')
            break;
        testCase(tmp);
    }
    
    return 0;
}
