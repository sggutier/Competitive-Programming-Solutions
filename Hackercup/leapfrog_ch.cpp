#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

bool testCase(const string &s) {
    vector <int> cnt(300);
    for(const char c : s) {
        cnt[(int) c] ++;
    }
    int N = s.size()-1;
    int b = cnt['B'];
    return b <= N-1 && b*2 >= N;
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
