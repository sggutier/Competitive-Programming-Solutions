#include <bits/stdc++.h>
using namespace std;

bool testCase(const string &s) {
    vector <int> cnt(300);
    for(const char c : s) {
        cnt[(int) c] ++;
    }
    int N = s.size()-1;
    int b = cnt['B'];
    if(b >= N)
        return false;
    if(N <= 4)
        return b*2 >= N;
    return b >= 2;
}

int main() {
    int N ;
    cin >> N;
    for(int i=1; i<=N; i++) {
        string s ;
        cin >> s ;
        printf("Case #%d: %c\n", i, testCase(s)? 'Y' : 'N');
    }
}
