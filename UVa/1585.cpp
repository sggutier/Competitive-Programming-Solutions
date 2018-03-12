#include <bits/stdc++.h>
using namespace std;

int testCase(string S) {
    int cnt = 0, ans = 0;
    for(auto &c: S) {
        if(c=='X') {
            cnt = 0;
        }
        else {
            cnt ++;
            ans += cnt;
        }
    }
    return ans;
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--) {
        char tmp[100];
        scanf("%s", tmp);
        printf("%d\n", testCase(tmp));
    }
    
    return 0 ;
}
