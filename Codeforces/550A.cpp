#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int cnt[limN][2];

int main() {
    string s ;
    int n;
    cin >> s ;
    n = s.size();

    for(int i=n-2; i>=0; i--) {
        cnt[i][0] = cnt[i+1][0];
        cnt[i][1] = cnt[i+1][1];
        if(s[i]=='A' && s[i+1]=='B') {
            cnt[i][0] ++;
            if(cnt[i+2][1]) {
                printf("YES\n");
                return 0;
            }
        }
        else if(s[i]=='B' && s[i+1]=='A') {
            cnt[i][1] ++;
            if(cnt[i+2][0]) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
}
